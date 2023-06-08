
#pragma once

#include "re_core/visualization/proto/view_update.pb.h"
#include "re_core/visualization/view_update.hh"

namespace re::visualization::proto {

void pack(const visualization::ViewUpdate &in, ViewUpdate *out);

visualization::ViewUpdate unpack(const ViewUpdate &in);

};  // namespace re::visualization::proto
