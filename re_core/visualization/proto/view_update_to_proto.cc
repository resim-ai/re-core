
#include "re_core/visualization/proto/view_update_to_proto.hh"

#include "re_core/assert/assert.hh"
#include "re_core/visualization/proto/view_primitive_to_proto.hh"

namespace resim::visualization::proto {

void pack(const visualization::ViewUpdate &in, ViewUpdate *const out) {
  REASSERT(out != nullptr, "Can't pack into invalid proto!");
  out->Clear();
  for (const auto &primitive : in.primitives) {
    pack(primitive, out->add_primitive());
  }
}

visualization::ViewUpdate unpack(const ViewUpdate &in) {
  visualization::ViewUpdate result;
  result.primitives.reserve(in.primitive().size());
  for (const auto &primitive : in.primitive()) {
    result.primitives.push_back(unpack(primitive));
  }
  return result;
}

};  // namespace resim::visualization::proto