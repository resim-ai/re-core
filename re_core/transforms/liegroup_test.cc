#include <gtest/gtest.h>

#include <Eigen/Dense>
#include <vector>

#include "re_core/transforms/liegroup_test_helpers.hh"
#include "re_core/transforms/se3.hh"
#include "re_core/transforms/so3.hh"

namespace resim::transforms {

// Common tests that apply over all LieGroup classes, for example: SO3, SE3.
// For specialized tests see the test files for the classes themselves, for
// example so3_test.cc
template <typename t>
class LieGroupTests : public ::testing::Test {};

using LieGroupTypes = ::testing::Types<SO3, SE3>;
TYPED_TEST_SUITE(LieGroupTests, LieGroupTypes);

TYPED_TEST(LieGroupTests, InverseNegativeAlgEquivalence) {
  for (const typename TypeParam::TangentVector &alg :
       make_test_algebra_elements<TypeParam>()) {
    const TypeParam b_from_a_ref = TypeParam::exp(alg).inverse();
    const TypeParam b_from_a = TypeParam::exp(-alg);
    EXPECT_TRUE(b_from_a_ref.is_approx(b_from_a));
  }
}

TYPED_TEST(LieGroupTests, InterpZeroIdentity) {
  // Confirm interpolating at zero gives identity.
  constexpr double ZERO = 0;
  for (const TypeParam &a_from_b : make_test_group_elements<TypeParam>()) {
    EXPECT_TRUE(a_from_b.interp(ZERO).is_approx(TypeParam::identity()));
  }
}

TYPED_TEST(LieGroupTests, InterpOneNoop) {
  // Confirm interpolating at one is a noop.
  constexpr double ONE = 1.;
  for (const TypeParam &a_from_b : make_test_group_elements<TypeParam>()) {
    EXPECT_TRUE(a_from_b.interp(ONE).is_approx(a_from_b));
  }
}

TYPED_TEST(LieGroupTests, ExpOfZero) {
  TypeParam a_from_a_ref = TypeParam::identity();
  TypeParam a_from_a = TypeParam::exp(TypeParam::TangentVector::Zero());
  EXPECT_TRUE(a_from_a_ref.is_approx(a_from_a));
}

TYPED_TEST(LieGroupTests, LogOfIdentity) {
  const TypeParam a_from_a = TypeParam::identity();
  // Test log of identity TypeParam is zero.
  EXPECT_TRUE(a_from_a.log().isApprox(TypeParam::TangentVector::Zero()));
}

TYPED_TEST(LieGroupTests, ExpOfLogNoop) {
  std::vector<TypeParam> test_elements = make_test_group_elements<TypeParam>();
  // Exp should always be the inverse of log.
  for (const TypeParam &a_from_b : test_elements) {
    const TypeParam a_from_b_ref = TypeParam::exp(a_from_b.log());
    EXPECT_TRUE(a_from_b_ref.is_approx(a_from_b));
  }
}

TYPED_TEST(LieGroupTests, SelfAdjointNoop) {
  for (const typename TypeParam::TangentVector &alg :
       make_test_algebra_elements<TypeParam>()) {
    const TypeParam a_from_b = TypeParam::exp(alg);
    const typename TypeParam::TangentVector alg_noop =
        a_from_b.adjoint_times(a_from_b.log());
    EXPECT_TRUE(alg.isApprox(alg_noop));
  }
}

TYPED_TEST(LieGroupTests, CompositionByAdjoint) {
  const auto test_elements = make_test_group_elements<TypeParam>();
  const TypeParam &a_from_b = test_elements.back();
  for (const TypeParam &b_from_c : test_elements) {
    const TypeParam a_from_c_ref = a_from_b * b_from_c;
    const TypeParam a_from_c =
        TypeParam::exp(a_from_b.adjoint_times(b_from_c.log())) * a_from_b;
    EXPECT_TRUE(a_from_c_ref.is_approx(a_from_c));
  }
}

TYPED_TEST(LieGroupTests, AdjointAndTimesGroup) {
  using TangentVector = typename TypeParam::TangentVector;
  const auto test_elements = make_test_group_elements<TypeParam>();
  const TangentVector alg = test_elements.back().log();
  for (const TypeParam &grp : test_elements) {
    const TangentVector adj_times = grp.adjoint_times(alg);
    const TangentVector adj_times_alt = grp.adjoint() * alg;
    EXPECT_TRUE(adj_times.isApprox(adj_times_alt));
  }
}

TYPED_TEST(LieGroupTests, AdjointAndTimesAlgebra) {
  using TangentVector = typename TypeParam::TangentVector;
  const auto test_alg_elements = make_test_algebra_elements<TypeParam>();
  const TangentVector &b = test_alg_elements.back();
  for (const TangentVector &a : test_alg_elements) {
    const TangentVector adj_times = TypeParam::adjoint_times(a, b);
    const TangentVector adj_times_alt = TypeParam::adjoint(a) * b;
    // isApprox struggles when vectors are close to zero.
    constexpr double TOLERANCE = 1e-9;
    EXPECT_TRUE((adj_times - adj_times_alt).isZero(TOLERANCE));
  }
}

TYPED_TEST(LieGroupTests, AlgebraAdjointAntiCommutative) {
  using TangentVector = typename TypeParam::TangentVector;
  const auto test_alg_elements = make_test_algebra_elements<TypeParam>();
  const TangentVector &b = test_alg_elements.back();
  for (const TangentVector &a : test_alg_elements) {
    const TangentVector x = TypeParam::adjoint_times(a, b);
    const TangentVector y = TypeParam::adjoint_times(b, a);
    // One of our test vectors is close to zero and isApprox struggles close to
    // zero.
    constexpr double TOLERANCE = 1e-9;
    EXPECT_TRUE((x + y).isZero(TOLERANCE));
  }
}

TYPED_TEST(LieGroupTests, FloatingPointEquality) {
  const auto test_elements = make_test_group_elements<TypeParam>();
  const TypeParam &a_from_a = test_elements.front();
  for (auto test_elements_it = test_elements.begin() + 1;
       test_elements_it < test_elements.end();
       ++test_elements_it) {
    const TypeParam &a_from_b = *test_elements_it;
    const TypeParam &a_from_b_cp = *test_elements_it;
    EXPECT_TRUE(a_from_b.is_approx(a_from_b_cp));
    // Given that all the test elements are guaranteed to be unique - a
    // constraint that is enforced in the test for the helper lib - then it is
    // reasonable to expect the below to test to return false consistently.
    EXPECT_FALSE(a_from_a.is_approx(a_from_b));
  }
}

}  // namespace resim::transforms