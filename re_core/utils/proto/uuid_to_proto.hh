// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.


#pragma once

#include "re_core/utils/proto/uuid.pb.h"
#include "re_core/utils/uuid.hh"

namespace re::proto {

void pack(const re::UUID &in, UUID *out);

re::UUID unpack(const UUID &in);

};  // namespace re::proto
