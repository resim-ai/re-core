// Copyright 2023 ReSim, Inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.


#pragma once

#include <optional>
#include <string>
#include <variant>

#include "re_core/actor/state/trajectory.hh"
#include "re_core/curves/d_curve.hh"
#include "re_core/curves/t_curve.hh"
#include "re_core/transforms/frame.hh"
#include "re_core/transforms/framed_vector.hh"
#include "re_core/transforms/se3.hh"
#include "re_core/transforms/so3.hh"
#include "re_core/utils/uuid.hh"

namespace re::visualization {

// A struct representing a single visualizable piece of data (e.g. a transform,
// curve, box, etc.), its optional, user-supplied name and metadata about that
// view object.
struct ViewPrimitive {
  UUID id;
  std::variant<
      transforms::SE3,
      transforms::SO3,
      curves::DCurve<transforms::SE3>,
      curves::TCurve<transforms::SE3>,
      actor::state::Trajectory,
      transforms::Frame<3>,
      transforms::FramedVector<3>>
      payload;
  std::optional<std::string> user_defined_name = {};
  // The file name and line number where this view primitive was created.
  std::string file_name;
  int line_number;
};

}  // namespace re::visualization
