#include "re_core/visualization/testing/test_helpers.hh"

#include <gtest/gtest.h>

#include <random>

#include "re_core/testing/random_matrix.hh"
#include "re_core/transforms/se3.hh"
#include "re_core/utils/uuid.hh"
#include "re_core/visualization/view_primitive.hh"

namespace re::visualization::testing {

using re::testing::random_vector;
using transforms::SE3;

TEST(ViewPrimitivesEqualTest, TestViewPrimitivesEqual) {
  // SETUP
  constexpr unsigned SEED = 93U;
  std::mt19937 rng{SEED};
  const ViewPrimitive test_primitive{
      .id = UUID::new_uuid(),
      .payload = SE3::exp(random_vector<SE3::TangentVector>(rng)),
  };

  const ViewPrimitive& equal_primitive{test_primitive};
  ViewPrimitive unequal_id{test_primitive};
  unequal_id.id = UUID::new_uuid();
  ViewPrimitive unequal_payload{test_primitive};
  unequal_payload.payload = SE3::exp(random_vector<SE3::TangentVector>(rng));

  // ACTION / VERIFICATION
  EXPECT_TRUE(primitives_equal(test_primitive, equal_primitive));
  EXPECT_FALSE(primitives_equal(test_primitive, unequal_id));
  EXPECT_FALSE(primitives_equal(test_primitive, unequal_payload));
}

}  // namespace re::visualization::testing
