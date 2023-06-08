#pragma once

#include "re_core/curves/proto/t_curve.pb.h"
#include "re_core/curves/t_curve.hh"
#include "re_core/transforms/se3.hh"

namespace re::curves::proto {

void pack(const TCurve<transforms::SE3> &in, TCurve_SE3 *out);

TCurve<transforms::SE3> unpack(const TCurve_SE3 &in);

}  // namespace re::curves::proto
