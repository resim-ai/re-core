#pragma once

#include "re_core/curves/proto/two_jet.pb.h"
#include "re_core/curves/two_jet.hh"
#include "re_core/transforms/se3.hh"

namespace re::curves::proto {

void pack(const TwoJetL<transforms::SE3> &in, TwoJetL_SE3 *out);

TwoJetL<transforms::SE3> unpack(const TwoJetL_SE3 &in);

}  // namespace re::curves::proto
