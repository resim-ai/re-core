
#pragma once

#include <string>
#include <variant>

#include "re_core/curves/d_curve.hh"
#include "re_core/transforms/framed_group.hh"
#include "re_core/transforms/se3.hh"
#include "re_core/transforms/so3.hh"
#include "re_core/utils/uuid.hh"

namespace resim::visualization {

// A struct representing a single visualizable piece of data (e.g. a transform,
// curve, box, etc.)
struct ViewPrimitive {
  UUID id;
  std::variant<
      transforms::SE3,
      transforms::SO3,
      curves::DCurve<transforms::SE3>,
      curves::DCurve<transforms::FSE3>>
      payload;
};

}  // namespace resim::visualization
