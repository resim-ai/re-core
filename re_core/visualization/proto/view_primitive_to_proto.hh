// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.


#pragma once

#include "re_core/utils/status_value.hh"
#include "re_core/visualization/proto/view_primitive.pb.h"
#include "re_core/visualization/view_primitive.hh"

namespace re::visualization::proto {

void pack(const visualization::ViewPrimitive &in, ViewPrimitive *out);

visualization::ViewPrimitive unpack(const ViewPrimitive &in);

namespace detail {

StatusValue<visualization::ViewPrimitive> unpack(const ViewPrimitive &in);

}

};  // namespace re::visualization::proto
