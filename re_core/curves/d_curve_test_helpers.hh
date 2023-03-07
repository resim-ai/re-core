#pragma once

#include <vector>

#include "re_core/curves/d_curve.hh"
#include "re_core/transforms/frame.hh"
#include "re_core/transforms/liegroup_concepts.hh"

namespace resim::curves {

template <transforms::LieGroupType Group>
class DCurveCircle {
 public:
  using Frame = transforms::Frame<Group::DIMS>;
  inline static const Frame REF_FRAME = Frame::new_frame();

  // Builds and returns a vector of Group that creates a unit circle.
  static std::vector<Group> points(const Frame &ref_frame = REF_FRAME);
};

}  // namespace resim::curves
