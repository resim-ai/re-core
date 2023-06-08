
#pragma once

#include "re_core/utils/proto/uuid.pb.h"
#include "re_core/utils/uuid.hh"

namespace re::proto {

void pack(const re::UUID &in, UUID *out);

re::UUID unpack(const UUID &in);

};  // namespace re::proto
