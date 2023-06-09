// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.


#pragma once

#include "re_core/visualization/proto/view_update.pb.h"
#include "re_core/visualization/view_update.hh"

namespace re::visualization::proto {

void pack(const visualization::ViewUpdate &in, ViewUpdate *out);

visualization::ViewUpdate unpack(const ViewUpdate &in);

};  // namespace re::visualization::proto
