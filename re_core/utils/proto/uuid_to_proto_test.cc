// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.


#include "re_core/utils/proto/uuid_to_proto.hh"

#include <gtest/gtest.h>

#include "re_core/assert/assert.hh"
#include "re_core/utils/proto/uuid.pb.h"
#include "re_core/utils/uuid.hh"

namespace re {

TEST(UUIDToProtoTest, TestPack) {
  // SETUP
  proto::UUID msg;
  const UUID uuid{UUID::new_uuid()};

  // ACTION
  pack(uuid, &msg);

  // VERIFICATION
  EXPECT_EQ(msg.data(), uuid.to_string());
}

TEST(UUIDToProtoTest, TestRoundTrip) {
  // SETUP
  proto::UUID msg;
  const UUID uuid{UUID::new_uuid()};

  // ACTION
  pack(uuid, &msg);
  const UUID other_uuid{unpack(msg)};

  // VERIFICATION
  EXPECT_EQ(uuid, other_uuid);
}

TEST(UUIDToProtoDeathTest, TestPackInvalid) {
  // ACTION / VERIFICATION
  EXPECT_THROW(proto::pack(UUID::new_uuid(), nullptr), AssertException);
}

}  // namespace re
