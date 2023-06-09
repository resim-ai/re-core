// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#pragma once

#include "re_core/transforms/proto/se3.pb.h"
#include "re_core/transforms/se3.hh"

namespace re::transforms::proto {

void pack(const transforms::SE3 &in, SE3 *out);

transforms::SE3 unpack(const SE3 &in);

}  // namespace re::transforms::proto
