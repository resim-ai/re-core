// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#pragma once

#include "re_core/curves/d_curve.hh"
#include "re_core/curves/proto/d_curve.pb.h"
#include "re_core/transforms/se3.hh"

namespace re::curves::proto {

void pack(const DCurve<transforms::SE3> &in, DCurve_SE3 *out);

DCurve<transforms::SE3> unpack(const DCurve_SE3 &in);

}  // namespace re::curves::proto
