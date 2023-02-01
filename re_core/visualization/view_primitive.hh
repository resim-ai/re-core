
#pragma once

#include <string>
#include <variant>

#include "re_core/transforms/se3.hh"
#include "re_core/utils/uuid.hh"

namespace resim::visualization {

// A struct representing a single visualizable piece of data (e.g. a transform,
// curve, box, etc.)
struct ViewPrimitive {
  UUID id;
  std::variant<transforms::SE3> payload;
};

}  // namespace resim::visualization
