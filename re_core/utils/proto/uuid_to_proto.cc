

#include "re_core/utils/proto/uuid_to_proto.hh"

#include "re_core/assert/assert.hh"

namespace re::proto {

void pack(const re::UUID &in, UUID *const out) {
  REASSERT(out != nullptr, "Can't pack into invalid proto!");
  out->Clear();
  out->set_data(in.to_string());
}

re::UUID unpack(const UUID &in) { return re::UUID{in.data()}; }

};  // namespace re::proto
