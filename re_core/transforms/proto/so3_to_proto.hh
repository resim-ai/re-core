#pragma once

#include "re_core/transforms/proto/so3.pb.h"
#include "re_core/transforms/so3.hh"

namespace resim::transforms::proto {

void pack(const transforms::SO3 &in, SO3 *out);

transforms::SO3 unpack(const SO3 &in);

}  // namespace resim::transforms::proto
