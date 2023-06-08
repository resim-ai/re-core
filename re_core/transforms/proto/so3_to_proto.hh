#pragma once

#include "re_core/transforms/proto/so3.pb.h"
#include "re_core/transforms/so3.hh"

namespace re::transforms::proto {

void pack(const transforms::SO3 &in, SO3 *out);

transforms::SO3 unpack(const SO3 &in);

}  // namespace re::transforms::proto
