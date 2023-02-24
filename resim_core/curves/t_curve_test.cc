#include "resim_core/curves/t_curve.hh"

#include <gtest/gtest.h>

#include "resim_core/curves/two_jet.hh"
#include "resim_core/curves/two_jet_test_helpers.hh"
#include "resim_core/testing/random_matrix.hh"
#include "resim_core/transforms/framed_group.hh"
#include "resim_core/transforms/framed_group_concept.hh"
#include "resim_core/transforms/se3.hh"
#include "resim_core/transforms/so3.hh"

namespace resim::curves {

namespace {
using SE3 = transforms::SE3;
using SO3 = transforms::SO3;
using FSE3 = transforms::FSE3;
using FSO3 = transforms::FSO3;
}  // namespace

// An explicit seed for deterministic generation of test objects.
constexpr unsigned int SEED = 401;

template <typename Group>
class TCurveTests : public ::testing::Test {
 public:
  using Frame = transforms::Frame<Group::DIMS>;
  inline static const Frame REF_FRAME = Frame::new_frame();
  inline static const Frame POINT_FRAME = Frame::new_frame();
  inline static const std::vector<double> DEFAULT_TIMES{0.0, 0.15, 0.71};

 protected:
  void SetUp() override { tj_helper_ = TwoJetTestHelper<TwoJetL<Group>>(SEED); }
  TwoJetTestHelper<TwoJetL<Group>> &tj_helper() { return tj_helper_; }
  TwoJetL<Group> test_two_jet(const Frame &into) requires
      transforms::FramedGroupType<Group> {
    TwoJetL<Group> test_tj = tj_helper().make_test_two_jet();
    Group group = test_tj.frame_from_ref();
    group.set_into(into);
    group.set_from(REF_FRAME);
    test_tj.set_frame_from_ref(group);
    return test_tj;
  }

  TCurve<Group> test_curve(const std::vector<double> &times) {
    TCurve<Group> test_curve;
    for (const double &t : times) {
      test_curve.append({t, tj_helper().make_test_two_jet()});
    }
    return test_curve;
  }

  TCurve<Group> test_curve(const std::vector<double> &times) requires
      transforms::FramedGroupType<Group> {
    TCurve<Group> test_curve;
    for (const double &t : times) {
      test_curve.append({t, test_two_jet(POINT_FRAME)});
    }
    return test_curve;
  }

  TCurve<Group> test_curve_default() { return test_curve(DEFAULT_TIMES); }

 private:
  TwoJetTestHelper<TwoJetL<Group>> tj_helper_;
};

using LieGroupTypes = ::testing::Types<FSE3, FSO3, SE3, SO3>;
TYPED_TEST_SUITE(TCurveTests, LieGroupTypes);

template <typename Group>
class FramedTCurveTests : public TCurveTests<Group> {};

using FramedTypes = ::testing::Types<FSE3, FSO3>;
TYPED_TEST_SUITE(FramedTCurveTests, FramedTypes);

TYPED_TEST(TCurveTests, EmptyCurveConstruction) {
  // Create and empty curve.
  TCurve<TypeParam> curve_a;
  // Confirm it's empty.
  EXPECT_TRUE(curve_a.control_pts().empty());
  EXPECT_TRUE(curve_a.segments().empty());
}

TYPED_TEST(TCurveTests, VectorConstruction) {
  // Create default curve.
  TCurve<TypeParam> curve_a = this->test_curve_default();
  // Create another curve from the control points of the first.
  TCurve<TypeParam> curve_b(curve_a.control_pts());
  // Confirm the control points are the same.
  for (unsigned int i = 0; i < curve_a.control_pts().size(); ++i) {
    EXPECT_DOUBLE_EQ(
        curve_a.control_pts().at(i).time,
        curve_b.control_pts().at(i).time);
    EXPECT_TRUE(curve_a.control_pts().at(i).point.is_approx(
        curve_a.control_pts().at(i).point));
  }
}

TYPED_TEST(TCurveTests, ListInitializationConstruction) {
  constexpr unsigned int NUM_POINTS = 3;
  // Create default curve.
  TCurve<TypeParam> curve_a = this->test_curve_default();
  ASSERT_GE(curve_a.control_pts().size(), NUM_POINTS);
  TCurve<TypeParam> curve_b{
      curve_a.control_pts().at(0),
      curve_a.control_pts().at(1),
      curve_a.control_pts().at(2)};
  // Confirm the control points are the same.
  for (unsigned int i = 0; i < NUM_POINTS; ++i) {
    EXPECT_DOUBLE_EQ(
        curve_a.control_pts().at(i).time,
        curve_b.control_pts().at(i).time);
    EXPECT_TRUE(curve_a.control_pts().at(i).point.is_approx(
        curve_a.control_pts().at(i).point));
  }
}

TYPED_TEST(TCurveTests, ListInitializationAssignment) {
  constexpr unsigned int NUM_POINTS = 3;
  // Create default curve.
  TCurve<TypeParam> curve_a = this->test_curve_default();
  ASSERT_GE(curve_a.control_pts().size(), NUM_POINTS);
  TCurve<TypeParam> curve_b = {
      curve_a.control_pts().at(0),
      curve_a.control_pts().at(1),
      curve_a.control_pts().at(2)};
  // Confirm the control points are the same.
  for (unsigned int i = 0; i < NUM_POINTS; ++i) {
    EXPECT_DOUBLE_EQ(
        curve_a.control_pts().at(i).time,
        curve_b.control_pts().at(i).time);
    EXPECT_TRUE(curve_a.control_pts().at(i).point.is_approx(
        curve_a.control_pts().at(i).point));
  }
}

TYPED_TEST(TCurveTests, ListInitializationAppend) {
  constexpr unsigned int NUM_POINTS = 3;
  // Create default curve.
  TCurve<TypeParam> curve_a = this->test_curve_default();
  ASSERT_GE(curve_a.control_pts().size(), NUM_POINTS);
  TCurve<TypeParam> curve_b{curve_a.control_pts().at(0)};
  curve_b.append({curve_a.control_pts().at(1), curve_a.control_pts().at(2)});
  // Confirm the control points are the same.
  for (unsigned int i = 0; i < NUM_POINTS; ++i) {
    EXPECT_DOUBLE_EQ(
        curve_a.control_pts().at(i).time,
        curve_b.control_pts().at(i).time);
    EXPECT_TRUE(curve_a.control_pts().at(i).point.is_approx(
        curve_a.control_pts().at(i).point));
  }
}

TYPED_TEST(TCurveTests, ControlAndSegmentDataCheck) {
  // Create default curve.
  TCurve<TypeParam> curve_a = this->test_curve_default();
  // Confirm that there are one less segments than control points - as
  // expected.
  const size_t ctrl_count = curve_a.control_pts().size();
  EXPECT_EQ(ctrl_count - 1, curve_a.segments().size());
}

TYPED_TEST(TCurveTests, CanRecoverControlPoints) {
  // Create default curve.
  TCurve<TypeParam> curve_a = this->test_curve_default();
  // Querying the curve exactly on the control points should recover the
  // control points.
  for (const auto &control_pt : curve_a.control_pts()) {
    EXPECT_TRUE(control_pt.point.is_approx(curve_a.point_at(control_pt.time)));
  }
}

TYPED_TEST(TCurveTests, NormalizedSegments) {
  // Create a curve with segments on exactly unit time.
  TCurve<TypeParam> curve_a = this->test_curve({-1.0, 0.0, 1.0});
  const auto &control_points = curve_a.control_pts();
  const auto &segments = curve_a.segments();
  // Confirm that normalization is a noop by checking that the points in the
  // segments (normalized) are the same as the control points (un-normalized)
  for (int i : {0, 1}) {
    const auto &orig = segments.at(i).curve.orig();
    const auto &dest = segments.at(i).curve.dest();
    const auto &ctrl_o = control_points.at(i).point;
    const auto &ctrl_d = control_points.at(i + 1).point;
    EXPECT_TRUE(ctrl_o.is_approx(orig));
    EXPECT_TRUE(ctrl_d.is_approx(dest));
  }
  // Test a negative case.
  TCurve<TypeParam> curve_b = this->test_curve_default();
  EXPECT_FALSE(curve_b.control_pts().at(0).point.is_approx(
      curve_b.segments().at(0).curve.orig()));
}

TYPED_TEST(TCurveTests, DeathTestsForChecks) {
  constexpr double T_DELTA = 3.0;
  // Create constants above and below the time range of the default curve.
  const double HI_TIME = TestFixture::DEFAULT_TIMES.back() + T_DELTA;
  const double LO_TIME = TestFixture::DEFAULT_TIMES.front() - T_DELTA;
  // Create default curve.
  TCurve<TypeParam> curve_a = this->test_curve_default();
  // Time must increase with each point added to the curve, test a negative
  // case.
  EXPECT_DEATH(
      {
        curve_a.append({LO_TIME, TestFixture::tj_helper().make_test_two_jet()});
      },
      "Control points must have strictly increasing time");
  if constexpr (transforms::FramedGroupType<TypeParam>) {
    // Make a reference frame reversed control point.
    TwoJetL<TypeParam> last_point = curve_a.control_pts().back().point;
    TypeParam last_frame_from_ref = last_point.frame_from_ref();
    typename TCurveTests<TypeParam>::Frame last_from =
        last_frame_from_ref.from();
    last_frame_from_ref.set_from(last_frame_from_ref.into());
    last_point.set_frame_from_ref(last_frame_from_ref);
    // Try to add the point to the curve.
    EXPECT_DEATH(
        {
          curve_a.append({HI_TIME, last_point});
        },
        "Control points must all have the same ref and point frame");

    // Make a point frame reversed control point.
    last_frame_from_ref.set_from(last_from);
    last_frame_from_ref.set_into(last_from);
    last_point.set_frame_from_ref(last_frame_from_ref);
    // Try to add the point to the curve.
    EXPECT_DEATH(
        {
          curve_a.append({HI_TIME, last_point});
        },
        "Control points must all have the same ref and point frame");
  }
  // Try querying and empty curve
  TCurve<TypeParam> empty_curve;
  EXPECT_DEATH(
      {
        const double bad_start = empty_curve.start_time();
        (void)bad_start;  // Avoid unused variable errors.
      },
      "Cannot query the frame of a curve with no control points");
  EXPECT_DEATH(
      {
        const double bad_end = empty_curve.end_time();
        (void)bad_end;  // Avoid unused variable errors.
      },
      "Cannot query the frame of a curve with no control points");
  EXPECT_DEATH(
      {
        const TwoJetL<TypeParam> bad_point = empty_curve.point_at(1.0);
        (void)bad_point;  // Avoid unused variable errors.
      },
      "Cannot query a curve with less than two control points");
  if constexpr (transforms::FramedGroupType<TypeParam>) {
    // Empty point and reference frame
    EXPECT_DEATH(
        {
          const typename TCurveTests<TypeParam>::Frame bad_frame =
              empty_curve.point_frame();
          (void)bad_frame;  // Avoid unused variable errors.
        },
        "Cannot query the frame of a curve with no control points");
    EXPECT_DEATH(
        {
          const typename TCurveTests<TypeParam>::Frame bad_frame =
              empty_curve.reference_frame();
          (void)bad_frame;  // Avoid unused variable errors.
        },
        "Cannot query the frame of a curve with no control points");
  }
  // Try querying a curve below its time range.
  EXPECT_DEATH(
      {
        const TwoJetL<TypeParam> bad_point = curve_a.point_at(LO_TIME);
        (void)bad_point;  // Avoid unused variable errors.
      },
      "Query time must be within the range of times in the control points.");
  // Try querying a curve above its time range.
  EXPECT_DEATH(
      {
        const TwoJetL<TypeParam> bad_point = curve_a.point_at(HI_TIME);
        (void)bad_point;  // Avoid unused variable errors.
      },
      "Query time must be within the range of times in the control points.");
}

TYPED_TEST(TCurveTests, NumericalVsAnalyticalDerivatives) {
  constexpr unsigned int NUM_TRIES = 7;
  const std::vector<double> test_t_vals{0.1, 0.3, 0.5, 0.7};
  constexpr double EPS = 1.E-5;
  for (unsigned int i = 0; i < NUM_TRIES; ++i) {
    // Create a random test curve.
    const TCurve curve = this->test_curve_default();
    for (const double time : test_t_vals) {
      // Query the test curve at n_time.
      const TwoJetL<TypeParam> point = curve.point_at(time);

      // Compute numerical derivatives at this point.
      const TwoJetL<TypeParam> upstr = curve.point_at(time - EPS);
      const TwoJetL<TypeParam> dnstr = curve.point_at(time + EPS);

      const typename TypeParam::TangentVector num_d_frame_from_ref =
          (dnstr.frame_from_ref() * upstr.frame_from_ref().inverse()).log() /
          (2. * EPS);
      const typename TypeParam::TangentVector num_d2_frame_from_ref =
          (dnstr.d_frame_from_ref() - upstr.d_frame_from_ref()) / (2. * EPS);

      // Check numerical and analytical derivatives are the same within
      // tolerance of EPS.
      EXPECT_TRUE(point.d_frame_from_ref().isApprox(num_d_frame_from_ref, EPS));
      EXPECT_TRUE(
          point.d2_frame_from_ref().isApprox(num_d2_frame_from_ref, EPS));
    }
  }
}

TYPED_TEST(TCurveTests, DerivativesSmoothness) {
  // Create default curve.
  TCurve<TypeParam> curve = this->test_curve_default();
  // Confirm curve has interior points to query.
  constexpr unsigned int MIN_SIZE = 2;
  EXPECT_GT(curve.control_pts().size(), MIN_SIZE);
  // Query the curve near interior control points.
  constexpr double EPS = 1.E-9;
  constexpr double TOL = 1.E-4;
  for (auto cp_it = curve.control_pts().begin() + 1;
       cp_it != curve.control_pts().end() - 1;
       ++cp_it) {
    const double t = cp_it->time;
    // Query slightly upstream and downstream of the control points.
    const TwoJetL<TypeParam> upstr = curve.point_at(t - EPS);
    const TwoJetL<TypeParam> dnstr = curve.point_at(t + EPS);
    // Test that the derivatives are close to the same value.
    EXPECT_TRUE(
        upstr.d_frame_from_ref().isApprox(dnstr.d_frame_from_ref(), TOL));
    EXPECT_TRUE(
        upstr.d2_frame_from_ref().isApprox(dnstr.d2_frame_from_ref(), TOL));
  }
}

TYPED_TEST(TCurveTests, QueryStartAndEnd) {
  // Create default curve.
  const TCurve curve = this->test_curve_default();
  // Check the reference frame of the curve.
  EXPECT_EQ(curve.start_time(), TestFixture::DEFAULT_TIMES.front());
  EXPECT_EQ(curve.end_time(), TestFixture::DEFAULT_TIMES.back());
}

TYPED_TEST(FramedTCurveTests, RetrievePointWithFrame) {
  constexpr double QUERY_TIME = 0.53;
  // Create default curve.
  const TCurve curve = this->test_curve_default();
  // Query the curve with a caller supplied frame.
  TwoJetL<TypeParam> point = curve.point_at(QUERY_TIME);
  // Check that the retuned points frames are as expected.
  EXPECT_EQ(TCurveTests<TypeParam>::POINT_FRAME, point.frame_from_ref().into());
  EXPECT_EQ(TCurveTests<TypeParam>::REF_FRAME, point.frame_from_ref().from());
}

TYPED_TEST(FramedTCurveTests, QueryReferenceFrame) {
  // Create default curve.
  const TCurve curve = this->test_curve_default();
  // Check the reference frame of the curve.
  EXPECT_EQ(TCurveTests<TypeParam>::REF_FRAME, curve.reference_frame());
}

TYPED_TEST(FramedTCurveTests, QueryPointFrame) {
  // Create default curve.
  const TCurve curve = this->test_curve_default();
  // Check the point frame of the curve.
  EXPECT_EQ(TCurveTests<TypeParam>::POINT_FRAME, curve.point_frame());
}

}  // namespace resim::curves
