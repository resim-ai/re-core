
#pragma once

#include <vector>

#include "re_core/visualization/view_primitive.hh"

namespace re::visualization {

// A collection of view primitives to update the current state of the
// re::view visualization.
struct ViewUpdate {
  std::vector<ViewPrimitive> primitives;
};

}  // namespace re::visualization
