
#pragma once

#include "re_core/utils/proto/uuid.pb.h"
#include "re_core/utils/uuid.hh"

namespace resim::proto {

void pack(const resim::UUID &in, UUID *out);

resim::UUID unpack(const UUID &in);

};  // namespace resim::proto
