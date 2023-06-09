// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#pragma once

#include "re_core/curves/proto/two_jet.pb.h"
#include "re_core/curves/two_jet.hh"
#include "re_core/transforms/se3.hh"

namespace re::curves::proto {

void pack(const TwoJetL<transforms::SE3> &in, TwoJetL_SE3 *out);

TwoJetL<transforms::SE3> unpack(const TwoJetL_SE3 &in);

}  // namespace re::curves::proto
