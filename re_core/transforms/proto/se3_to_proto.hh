#pragma once

#include "re_core/transforms/proto/se3.pb.h"
#include "re_core/transforms/se3.hh"

namespace re::transforms::proto {

void pack(const transforms::SE3 &in, SE3 *out);

transforms::SE3 unpack(const SE3 &in);

}  // namespace re::transforms::proto
