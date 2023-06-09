// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#pragma once

#include "re_core/transforms/framed_vector.hh"
#include "re_core/transforms/proto/framed_vector_3.pb.h"

namespace re::transforms::proto {

void pack(const transforms::FramedVector<3> &in, FramedVector_3 *out);

transforms::FramedVector<3> unpack(const FramedVector_3 &in);

}  // namespace re::transforms::proto
