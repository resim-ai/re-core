#include "re_core/visualization/view_server/view_server_test_helper.hh"

#include <Eigen/Dense>

#include "re_core/actor/state/trajectory.hh"
#include "re_core/assert/assert.hh"
#include "re_core/curves/d_curve.hh"
#include "re_core/curves/d_curve_test_helpers.hh"
#include "re_core/curves/t_curve.hh"
#include "re_core/curves/test_helpers.hh"
#include "re_core/testing/random_matrix.hh"
#include "re_core/transforms/frame.hh"
#include "re_core/transforms/framed_vector.hh"
#include "re_core/transforms/liegroup_test_helpers.hh"
#include "re_core/transforms/se3.hh"
#include "re_core/transforms/so3.hh"

namespace resim::visualization::view_server {

namespace {
using transforms::SE3;
using transforms::SO3;
using Frame = transforms::Frame<SE3::DIMS>;
using FramedVector = transforms::FramedVector<3>;

constexpr auto LOW_COUNT =
    "The minimum number of test elements you can request is seven. Please "
    "increase the count.";

constexpr time::Timestamp ZERO_TIME;

Eigen::Matrix<double, 3, 1> generate_test_vector_3D() {
  constexpr unsigned seed = 101;
  std::mt19937 rng{seed};
  return testing::random_vector<Eigen::Matrix<double, 3, 1>>(rng);
}

}  // namespace

template <>
std::vector<Frame> generate_payload_type(const unsigned count, bool framed) {
  // How many test elements to make.
  REASSERT(count >= detail::MIN_TEST_ELEMENTS, LOW_COUNT);
  std::vector<Frame> frames;
  frames.reserve(count);
  for (int i = 0; i < count; i++) {
    Frame frame{Frame::new_frame()};
    frames.push_back(frame);
  }
  return frames;
}

template <>
std::vector<SE3> generate_payload_type(const unsigned count, bool framed) {
  // How many test elements to make.
  REASSERT(count >= detail::MIN_TEST_ELEMENTS, LOW_COUNT);
  std::vector<transforms::SE3> points;
  for (auto &element : transforms::make_test_group_elements<SE3>(count)) {
    // Ensure each element has a unique frame
    if (framed) {
      const auto pt_frame = Frame::new_frame();
      const auto ref_frame = Frame::new_frame();
      element.set_frames(ref_frame, pt_frame);
    } else {
      element.set_unframed();
    }
    points.emplace_back(element);
  }
  return points;
}

template <>
std::vector<SO3> generate_payload_type(const unsigned count, bool framed) {
  // How many test elements to make.
  REASSERT(count >= detail::MIN_TEST_ELEMENTS, LOW_COUNT);
  std::vector<transforms::SO3> points;
  for (auto &element : transforms::make_test_group_elements<SO3>(count)) {
    // Ensure each element has a unique frame
    if (framed) {
      const auto pt_frame = Frame::new_frame();
      const auto ref_frame = Frame::new_frame();
      element.set_frames(ref_frame, pt_frame);
    } else {
      element.set_unframed();
    }
    points.emplace_back(element);
  }
  return points;
}

template <>
std::vector<curves::DCurve<SE3>> generate_payload_type(
    const unsigned count,
    bool framed) {
  // How many test elements to make.
  REASSERT(count >= detail::MIN_TEST_ELEMENTS, LOW_COUNT);
  std::vector<curves::DCurve<SE3>> d_curves;
  d_curves.reserve(count);

  for (int i = 0; i < count; i++) {
    // Make sure we get both framed and unframed curves:
    if (framed) {
      curves::DCurve<SE3> curve(curves::DCurveCircle<SE3>::points());
      d_curves.push_back(curve);
    } else {
      curves::DCurve<SE3> curve(
          curves::DCurveCircle<SE3>::points(Frame(), Frame()));
      d_curves.push_back(curve);
    }
  }
  return d_curves;
}

template <>
std::vector<curves::TCurve<transforms::SE3>> generate_payload_type(
    const unsigned count,
    bool framed) {
  // How many test elements to make.
  REASSERT(count >= detail::MIN_TEST_ELEMENTS, LOW_COUNT);
  std::vector<curves::TCurve<transforms::SE3>> t_curves;
  const Frame into{framed ? Frame::new_frame() : Frame()};
  const Frame from{framed ? Frame::new_frame() : Frame()};
  t_curves.reserve(count);

  for (int i = 0; i < count; i++) {
    const curves::TCurve<transforms::SE3> test_curve{
        curves::testing::make_circle_curve(into, from)};
    t_curves.push_back(test_curve);
  }

  return t_curves;
}

template <>
std::vector<actor::state::Trajectory> generate_payload_type(
    const unsigned count,
    bool framed /* unused */) {
  REASSERT(count >= detail::MIN_TEST_ELEMENTS, LOW_COUNT);
  std::vector<actor::state::Trajectory> trajectories;
  constexpr bool TRAJECTORIES_ALWAYS_FRAMED = true;
  std::vector<curves::TCurve<transforms::SE3>> t_curves =
      generate_payload_type<curves::TCurve<transforms::SE3>>(
          count,
          TRAJECTORIES_ALWAYS_FRAMED);
  trajectories.reserve(count);

  for (int i = 0; i < count; i++) {
    const actor::state::Trajectory test_trajectory{t_curves.at(i), ZERO_TIME};
    trajectories.push_back(test_trajectory);
  }

  return trajectories;
}

template <>
std::vector<FramedVector> generate_payload_type(
    const unsigned count,
    bool framed /* unused */) {  // We don't support regular vectors, so this
                                 // argument is unused.
  std::vector<FramedVector> framed_vectors;
  framed_vectors.reserve(count);

  for (int i = 0; i < count; i++) {
    FramedVector test_vector(generate_test_vector_3D());
    framed_vectors.push_back(test_vector);
  }

  return framed_vectors;
}

}  // namespace resim::visualization::view_server
