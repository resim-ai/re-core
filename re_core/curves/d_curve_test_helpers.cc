#include "re_core/curves/d_curve_test_helpers.hh"

#include <gtest/gtest.h>

#include "re_core/assert/assert.hh"
#include "re_core/curves/d_curve.hh"
#include "re_core/transforms/framed_group.hh"
#include "re_core/transforms/se3.hh"

namespace resim::curves {

namespace {
using SE3 = transforms::SE3;
using SO3 = transforms::SO3;
using FSE3 = transforms::FSE3;
}  // namespace

template <>
std::vector<SE3> DCurveCircle<SE3>::points(const Frame &ref_frame) {
  std::vector<SE3> points;
  const SE3 ref_from_000deg(Eigen::Vector3d::UnitX());
  points.push_back(ref_from_000deg);
  const SE3 ref_from_090deg(
      SO3(Eigen::AngleAxisd(M_PI / 2, Eigen::Vector3d::UnitZ())),
      Eigen::Vector3d::UnitY());
  points.push_back(ref_from_090deg);
  const SE3 ref_from_180deg(
      SO3(Eigen::AngleAxisd(M_PI, Eigen::Vector3d::UnitZ())),
      -Eigen::Vector3d::UnitX());
  points.push_back(ref_from_180deg);
  const SE3 ref_from_270deg(
      SO3(Eigen::AngleAxisd(3 * M_PI / 2, Eigen::Vector3d::UnitZ())),
      -Eigen::Vector3d::UnitY());
  points.push_back(ref_from_270deg);
  return points;
}

template <>
std::vector<FSE3> DCurveCircle<FSE3>::points(const Frame &ref_frame) {
  auto raw_se3_points = DCurveCircle<SE3>::points();
  std::vector<FSE3> points;
  for (auto &point : raw_se3_points) {
    const auto pt_frame = transforms::Frame<SE3::DIMS>::new_frame();
    points.emplace_back(FSE3(std::move(point), ref_frame, pt_frame));
  }
  return points;
}

}  // namespace resim::curves
