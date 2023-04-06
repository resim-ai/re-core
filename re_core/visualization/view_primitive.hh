
#pragma once

#include <string>
#include <variant>

#include "re_core/actor/state/trajectory.hh"
#include "re_core/curves/d_curve.hh"
#include "re_core/curves/t_curve.hh"
#include "re_core/transforms/frame.hh"
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
      transforms::FSE3,
      transforms::FSO3,
      curves::DCurve<transforms::SE3>,
      curves::DCurve<transforms::FSE3>,
      curves::TCurve<transforms::FSE3>,
      actor::state::Trajectory,
      transforms::Frame<3>>
      payload;
};

}  // namespace resim::visualization
