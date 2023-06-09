// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "re_core/curves/proto/d_curve_se3_to_proto.hh"

#include "re_core/curves/proto/d_curve.pb.h"
#include "re_core/curves/proto/d_curve_to_proto.hh"
#include "re_core/transforms/se3.hh"
#include "re_core/utils/inout.hh"

namespace re::curves::proto {

void pack(const DCurve<transforms::SE3> &in, DCurve_SE3 *const out) {
  pack_d_curve(in, out);
}

DCurve<transforms::SE3> unpack(const DCurve_SE3 &in) {
  DCurve<transforms::SE3> d_curve_se3;
  unpack_d_curve(in, InOut(d_curve_se3));
  return d_curve_se3;
}

}  // namespace re::curves::proto
