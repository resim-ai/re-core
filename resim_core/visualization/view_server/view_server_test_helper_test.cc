#include "resim_core/visualization/view_server/view_server_test_helper.hh"

#include <gtest/gtest.h>

#include "resim_core/actor/state/trajectory.hh"
#include "resim_core/assert/assert.hh"
#include "resim_core/curves/d_curve.hh"
#include "resim_core/curves/d_curve_test_helpers.hh"
#include "resim_core/curves/t_curve.hh"
#include "resim_core/transforms/frame.hh"
#include "resim_core/transforms/se3.hh"
#include "resim_core/transforms/so3.hh"

namespace resim::visualization::view_server {

namespace {
using transforms::SE3;
using transforms::SO3;
using Frame = transforms::Frame<3>;

constexpr bool FRAMED = true;
constexpr bool UNFRAMED = false;
}  // namespace

template <typename Viewable>
class ViewServerHelperTests : public ::testing::Test {};

using ViewableTypes = ::testing::Types<
    SE3,
    SO3,
    curves::DCurve<SE3>,
    curves::TCurve<SE3>,
    actor::state::Trajectory,
    Frame>;

TYPED_TEST_SUITE(ViewServerHelperTests, ViewableTypes);

TYPED_TEST(ViewServerHelperTests, ReturnCounts) {
  const std::vector<TypeParam> default_results =
      generate_payload_type<TypeParam>();
  EXPECT_EQ(default_results.size(), detail::MIN_TEST_ELEMENTS);

  constexpr unsigned LRG_COUNT = 101;
  const auto large_results = generate_payload_type<TypeParam>(LRG_COUNT);
  EXPECT_EQ(large_results.size(), LRG_COUNT);
}

template <typename T>
using ViewServerHelperDeathTests = ViewServerHelperTests<T>;
TYPED_TEST_SUITE(ViewServerHelperDeathTests, ViewableTypes);

TYPED_TEST(ViewServerHelperDeathTests, TooFewElementsRequested) {
  constexpr unsigned TOO_FEW = detail::MIN_TEST_ELEMENTS - 1;
  EXPECT_THROW(
      {
        const auto test_vec = generate_payload_type<TypeParam>(TOO_FEW);
        (void)test_vec;
      },
      AssertException);
}

template <typename T>
void test_framed() {}

template <>
void test_framed<SO3>() {
  std::vector<SO3> framed_payloads =
      generate_payload_type<SO3>(detail::MIN_TEST_ELEMENTS, FRAMED);
  for (const auto &payload : framed_payloads) {
    EXPECT_TRUE(payload.is_framed());
  }

  std::vector<SO3> unframed_payloads =
      generate_payload_type<SO3>(detail::MIN_TEST_ELEMENTS, UNFRAMED);
  for (const auto &payload : unframed_payloads) {
    EXPECT_FALSE(payload.is_framed());
  }
}

template <>
void test_framed<SE3>() {
  std::vector<SE3> framed_payloads =
      generate_payload_type<SE3>(detail::MIN_TEST_ELEMENTS, FRAMED);
  for (const auto &payload : framed_payloads) {
    EXPECT_TRUE(payload.is_framed());
  }

  std::vector<SE3> unframed_payloads =
      generate_payload_type<SE3>(detail::MIN_TEST_ELEMENTS, UNFRAMED);
  for (const auto &payload : unframed_payloads) {
    EXPECT_FALSE(payload.is_framed());
  }
}

template <>
void test_framed<curves::DCurve<SE3>>() {
  std::vector<curves::DCurve<SE3>> framed_payloads =
      generate_payload_type<curves::DCurve<SE3>>(
          detail::MIN_TEST_ELEMENTS,
          FRAMED);
  for (const auto &payload : framed_payloads) {
    // TODO(https://app.asana.com/0/0/1204728047835811/f) use a helper for this
    EXPECT_TRUE(payload.control_pts().front().ref_from_control->is_framed());
  }

  std::vector<curves::DCurve<SE3>> unframed_payloads =
      generate_payload_type<curves::DCurve<SE3>>(
          detail::MIN_TEST_ELEMENTS,
          UNFRAMED);
  for (const auto &payload : unframed_payloads) {
    // TODO(https://app.asana.com/0/0/1204728047835811/f) use a helper for this
    EXPECT_FALSE(payload.control_pts().front().ref_from_control->is_framed());
  }
}

template <>
void test_framed<curves::TCurve<SE3>>() {
  std::vector<curves::TCurve<SE3>> framed_payloads =
      generate_payload_type<curves::TCurve<SE3>>(
          detail::MIN_TEST_ELEMENTS,
          FRAMED);
  for (const auto &payload : framed_payloads) {
    // TODO(https://app.asana.com/0/0/1204728047835811/f) use a helper for this
    EXPECT_TRUE(
        payload.control_pts().front().point.frame_from_ref().is_framed());
  }

  std::vector<curves::TCurve<SE3>> unframed_payloads =
      generate_payload_type<curves::TCurve<SE3>>(
          detail::MIN_TEST_ELEMENTS,
          UNFRAMED);
  for (const auto &payload : unframed_payloads) {
    // TODO(https://app.asana.com/0/0/1204728047835811/f) use a helper for this
    EXPECT_FALSE(
        payload.control_pts().front().point.frame_from_ref().is_framed());
  }
}

TYPED_TEST(ViewServerHelperTests, TestFramed) { test_framed<TypeParam>(); }

}  // namespace resim::visualization::view_server
