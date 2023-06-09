// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#pragma once

#include "re_core/transforms/frame.hh"
#include "re_core/transforms/proto/frame_3.pb.h"

namespace re::transforms::proto {

void pack(const transforms::Frame<3> &in, Frame_3 *out);

transforms::Frame<3> unpack(const Frame_3 &in);

};  // namespace re::transforms::proto
