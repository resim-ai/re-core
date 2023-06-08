#pragma once

#include "re_core/curves/proto/two_jet.pb.h"
#include "re_core/curves/two_jet.hh"
#include "re_core/transforms/so3.hh"

namespace re::curves::proto {

void pack(const TwoJetR<transforms::SO3> &in, TwoJetR_SO3 *out);

TwoJetR<transforms::SO3> unpack(const TwoJetR_SO3 &in);

}  // namespace re::curves::proto
