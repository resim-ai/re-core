
#include "re_core/visualization/proto/view_update_to_proto.hh"

#include <gtest/gtest.h>

#include "re_core/transforms/se3.hh"
#include "re_core/utils/match.hh"
#include "re_core/utils/uuid.hh"
#include "re_core/visualization/proto/view_primitive_to_proto.hh"
#include "re_core/visualization/proto/view_update.pb.h"
#include "re_core/visualization/testing/test_helpers.hh"
#include "re_core/visualization/view_primitive.hh"
#include "re_core/visualization/view_update.hh"

namespace resim::visualization {

using transforms::SE3;
using TangentVector = SE3::TangentVector;

namespace {
const TangentVector test_tangent{
    (TangentVector() << 1., 2., 3., 4., 5., 6.).finished()};

const SE3 test_se3{SE3::exp(test_tangent)};

const ViewPrimitive test_primitive{
    .id = UUID::new_uuid(),
    .payload = test_se3,
};

}  // namespace

TEST(ViewUpdateToProtoTest, TestPack) {
  // SETUP
  const ViewUpdate update{
      .primitives = {test_primitive, test_primitive},
  };

  proto::ViewUpdate update_msg;

  // ACTION
  pack(update, &update_msg);

  // VERIFICATION
  ASSERT_EQ(update_msg.primitive().size(), update.primitives.size());
  for (std::size_t ii = 0U; ii < update_msg.primitive().size(); ++ii) {
    const ViewPrimitive unpacked_primitive{
        unpack(update_msg.primitive(static_cast<int>(ii)))};
    EXPECT_TRUE(testing::primitives_equal(unpacked_primitive, test_primitive));
  }
}

TEST(ViewUpdateToProtoTest, TestRoundTrip) {
  // SETUP
  const ViewUpdate update{
      .primitives = {test_primitive, test_primitive},
  };

  proto::ViewUpdate update_msg;

  // ACTION
  pack(update, &update_msg);
  const ViewUpdate unpacked{unpack(update_msg)};

  // VERIFICATION
  ASSERT_EQ(update.primitives.size(), unpacked.primitives.size());
  for (const auto& primitive : update.primitives) {
    EXPECT_TRUE(testing::primitives_equal(primitive, test_primitive));
  }
}

TEST(ViewUpdateToProtoDeathTest, TestPackInvalid) {
  // SETUP
  const ViewUpdate update{
      .primitives = {test_primitive, test_primitive},
  };

  // ACTION / VERIFICATION
  EXPECT_DEATH(proto::pack(update, nullptr), "Can't pack into invalid proto!");
}

}  // namespace resim::visualization
