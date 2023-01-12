#include "re_core/curves/t_curve_segment.hh"

#include <gtest/gtest.h>

#include <random>

#include "re_core/curves/two_jet.hh"
#include "re_core/transforms/framed_group.hh"
#include "re_core/transforms/framed_group_concept.hh"
#include "re_core/transforms/se3.hh"
#include "re_core/transforms/so3.hh"
#include "re_core/utils/random_matrix.hh"

namespace resim::curves {

namespace {
using SO3 = transforms::SO3;
using SE3 = transforms::SE3;
using FSO3 = transforms::FSO3;
using FSE3 = transforms::FSE3;
}  // namespace

template <typename T>
class TCurveSegmentTests : public ::testing::Test {
 public:
  using Frame = transforms::Frame<T::DIMS>;
  inline static const Frame REF_FRAME = Frame::new_frame();
  inline static const Frame ORIG_FRAME = Frame::new_frame();
  inline static const Frame DEST_FRAME = Frame::new_frame();

 protected:
  void SetUp() override {
    constexpr unsigned int SEED = 401;
    rng_ = std::mt19937(SEED);
  }

  typename T::TangentVector test_vector() {
    return testing::random_vector<typename T::TangentVector>(rng_);
  }

  T test_group() { return T::exp(test_vector()); }

  T test_group(const Frame &into) requires transforms::FramedGroupType<T> {
    return T::exp(test_vector(), into, REF_FRAME);
  }

  T test_orig_group() { return test_group(); }

  T test_orig_group() requires transforms::FramedGroupType<T> {
    return test_group(ORIG_FRAME);
  }

  T test_dest_group() { return test_group(); }

  T test_dest_group() requires transforms::FramedGroupType<T> {
    return test_group(DEST_FRAME);
  }

  TwoJet<T> test_two_jet() {
    return TwoJet<T>(test_group(), test_vector(), test_vector());
  }

  TwoJet<T> test_two_jet(const Frame &into) requires
      transforms::FramedGroupType<T> {
    return TwoJet<T>(test_group(into), test_vector(), test_vector());
  }

  TCurveSegment<T> test_t_curve_segment() {
    return TCurveSegment<T>(this->test_two_jet(), this->test_two_jet());
  }

  TCurveSegment<T> test_t_curve_segment() requires
      transforms::FramedGroupType<T> {
    return TCurveSegment<T>(
        this->test_two_jet(ORIG_FRAME),
        this->test_two_jet(DEST_FRAME));
  }

 private:
  std::mt19937 rng_;
};

namespace {
// For each test below we employ (deterministic) randomly generated TwoJet
// objects. We desire to test a few different generated TwoJets in order to
// confirm the implementation is robust. This number should be more than 1.
// However, it does not need to be hundreds, because we are testing
// fundamental functionality which should not be susceptible to errors of high
// sensitivity. Seven is a (hopefully) lucky guess at the 'right' number.
constexpr unsigned int NUM_TRIES = 7;
}  // namespace

using LieGroupTypes = ::testing::Types<SO3, SE3, FSO3, FSE3>;
TYPED_TEST_SUITE(TCurveSegmentTests, LieGroupTypes);

template <typename T>
class FramedTCurveSegmentTests : public TCurveSegmentTests<T> {};

using FramedTypes = ::testing::Types<FSE3, FSO3>;
TYPED_TEST_SUITE(FramedTCurveSegmentTests, FramedTypes);

TYPED_TEST(FramedTCurveSegmentTests, ConstructionWithFrames) {
  // Test well formed costruction.
  EXPECT_NO_THROW({
    const TCurveSegment<TypeParam> good_curve = this->test_t_curve_segment();
    (void)good_curve;  // Avoid unused variable errors.
  });
  // Build a curve with non-matching ref frames.
  const TwoJet<TypeParam> orig = this->test_two_jet(this->ORIG_FRAME);
  const TwoJet<TypeParam> inv_dest =
      this->test_two_jet(this->DEST_FRAME).inverse();
  EXPECT_DEATH(
      {
        const TCurveSegment<TypeParam> bad_curve(orig, inv_dest);
        (void)bad_curve;  // Avoid unused variable errors.
      },
      "Origin and destination TwoJets must have the same reference frame.");
}

TYPED_TEST(TCurveSegmentTests, BoundaryConditionsRecover) {
  constexpr double ORIG_T = 0.;
  constexpr double DEST_T = 1.;
  for (unsigned int i = 0; i < NUM_TRIES; ++i) {
    // Create a test curve
    TCurveSegment<TypeParam> segment = this->test_t_curve_segment();
    // Query points at the boundaries
    TwoJet<TypeParam> orig = segment.point_at(ORIG_T);
    TwoJet<TypeParam> dest = segment.point_at(DEST_T);
    // Test that the queried points match the boundary points.
    EXPECT_TRUE(orig.is_approx(segment.orig()));
    EXPECT_TRUE(dest.is_approx(segment.dest()));
  }
}

TYPED_TEST(TCurveSegmentTests, ZeroDerivsReducesToGeodesicInterp) {
  constexpr double QUARTER = 0.25;
  constexpr double HALF = QUARTER + QUARTER;
  constexpr double THREEQUARTER = HALF + QUARTER;
  TwoJet<TypeParam> orig = TwoJet<TypeParam>::identity();
  TwoJet<TypeParam> dest = TwoJet<TypeParam>::identity();
  for (unsigned int i = 0; i < NUM_TRIES; ++i) {
    // Create a test curve with all derivatives set to zero.
    orig.set_frame_from_ref(this->test_orig_group());
    dest.set_frame_from_ref(this->test_dest_group());
    TCurveSegment<TypeParam> segment(orig, dest);

    // Query a point halfway along the curve.
    const TwoJet<TypeParam> halfway = segment.point_at(HALF);

    // Try a Geodesic interpolation to the halfway point.
    // In the case where the derivatives are the same at both boundaries, we
    // expect that the quintic Hermite curve will follow the same path as a
    // Geodesic curve.
    TypeParam orig_from_dest = segment.orig().frame_from_ref() *
                               segment.dest().frame_from_ref().inverse();
    TypeParam orig_from_point = orig_from_dest.interp(HALF);
    TypeParam point_from_ref =
        orig_from_point.inverse() * segment.orig().frame_from_ref();

    // Test that the location of the halfway point is the same.
    EXPECT_TRUE(halfway.frame_from_ref().is_approx(point_from_ref));
    // To achieve zero velocity at the boundary conditions the point must
    // accelerate and decelerate symmetrically with a zero acceleration  point
    // in the middle. Test this:
    EXPECT_TRUE(halfway.d2_frame_from_ref().isZero());
    const TwoJet<TypeParam> quarterway = segment.point_at(QUARTER);
    EXPECT_FALSE(quarterway.d2_frame_from_ref().isZero());
    const TwoJet<TypeParam> threequarterway = segment.point_at(THREEQUARTER);
    EXPECT_TRUE(quarterway.d2_frame_from_ref().isApprox(
        -threequarterway.d2_frame_from_ref()));
  }
}

TYPED_TEST(TCurveSegmentTests, ConstVReducesToGeodesicInterp) {
  constexpr double HALF = 0.5;
  constexpr double DOUBLE = 2.;
  TwoJet<TypeParam> orig = TwoJet<TypeParam>::identity();
  orig.set_d_frame_from_ref(TypeParam::TangentVector::Ones());
  TwoJet<TypeParam> dest = orig;
  for (unsigned int i = 0; i < NUM_TRIES; ++i) {
    // Create a test curve with constant non-zero velocity at the boundaries.
    orig.set_frame_from_ref(this->test_orig_group());
    dest.set_frame_from_ref(this->test_dest_group());
    TCurveSegment<TypeParam> segment(orig, dest);

    // Query a point halfway along the curve.
    const TwoJet<TypeParam> halfway = segment.point_at(HALF);

    // Try a Geodesic interpolation to the halfway point.
    // In the case where the derivatives are the same at both boundaries, we
    // expect that the quintic Hermite curve will follow the same path as a
    // Geodesic curve.
    TypeParam orig_from_dest = segment.orig().frame_from_ref() *
                               segment.dest().frame_from_ref().inverse();
    TypeParam orig_from_point = orig_from_dest.interp(HALF);
    TypeParam point_from_ref =
        orig_from_point.inverse() * segment.orig().frame_from_ref();

    // Test that the location of the halfway point is the same.
    EXPECT_TRUE(halfway.frame_from_ref().is_approx(point_from_ref));

    // Confirm the negative case, for non constant velocity:
    TwoJet<TypeParam> dest_2 = dest;
    dest_2.set_d_frame_from_ref(DOUBLE * TypeParam::TangentVector::Ones());
    TCurveSegment<TypeParam> segment_2(orig, dest_2);
    const TwoJet<TypeParam> halfway_2 = segment_2.point_at(HALF);
    EXPECT_FALSE(halfway_2.frame_from_ref().is_approx(point_from_ref));
  }
}

TYPED_TEST(TCurveSegmentTests, NumericalDerivativesAreConsistent) {
  const std::vector<double> test_t_vals{0.2, 0.4, 0.6, 0.8};
  constexpr double EPS = 1.E-5;
  for (unsigned int i = 0; i < NUM_TRIES; ++i) {
    // Create a random test curve segment.
    const TCurveSegment<TypeParam> segment = this->test_t_curve_segment();
    for (const double n_time : test_t_vals) {
      // Query the test curve at n_time.
      const TwoJet<TypeParam> point = segment.point_at(n_time);

      // Compute numerical derivatives at this point.
      const TwoJet<TypeParam> upstr = segment.point_at(n_time - EPS);
      const TwoJet<TypeParam> dnstr = segment.point_at(n_time + EPS);

      const typename TypeParam::TangentVector num_d_frame_from_ref =
          (dnstr.frame_from_ref() * upstr.frame_from_ref().inverse()).log() /
          (2. * EPS);
      const typename TypeParam::TangentVector num_d2_frame_from_ref =
          (dnstr.d_frame_from_ref() - upstr.d_frame_from_ref()) / (2. * EPS);

      // Check numerical and analytical derivatives are the same within
      // tolerace of EPS.
      EXPECT_TRUE(point.d_frame_from_ref().isApprox(num_d_frame_from_ref, EPS));
      EXPECT_TRUE(
          point.d2_frame_from_ref().isApprox(num_d2_frame_from_ref, EPS));
    }
  }
}

}  // namespace resim::curves