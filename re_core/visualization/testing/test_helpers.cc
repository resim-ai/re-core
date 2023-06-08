
#include "re_core/visualization/testing/test_helpers.hh"

#include "re_core/transforms/se3.hh"
#include "re_core/utils/match.hh"

namespace re::visualization::testing {

using transforms::SE3;
using TangentVector = SE3::TangentVector;

bool primitives_equal(const ViewPrimitive &a, const ViewPrimitive &b) {
  if (a.id != b.id) {
    return false;
  }
  return std::get<SE3>(a.payload).is_approx(std::get<SE3>(b.payload));
}

}  // namespace re::visualization::testing
