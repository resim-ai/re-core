
#include "resim_core/visualization/proto/view_primitive_to_proto.hh"

#include "resim_core/assert/assert.hh"
#include "resim_core/curves/proto/d_curve_se3_to_proto.hh"
#include "resim_core/transforms/proto/se3_to_proto.hh"
#include "resim_core/utils/match.hh"
#include "resim_core/utils/proto/uuid_to_proto.hh"

namespace resim::visualization::proto {

void pack(const visualization::ViewPrimitive &in, ViewPrimitive *const out) {
  REASSERT(out != nullptr, "Can't pack into invalid proto!");
  out->Clear();
  pack(in.id, out->mutable_id());
  match(
      in.payload,
      [out](const transforms::SE3 &se3) { pack(se3, out->mutable_se3()); },
      [out](const curves::DCurve<transforms::SE3> &d_curve_se3) {
        pack(d_curve_se3, out->mutable_d_curve_se3());
      });
}

visualization::ViewPrimitive unpack(const ViewPrimitive &in) {
  StatusValue<visualization::ViewPrimitive> result_sv{detail::unpack(in)};
  CHECK_STATUS_OK(result_sv.status());
  return result_sv.value();
}

namespace detail {

StatusValue<visualization::ViewPrimitive> unpack(const ViewPrimitive &in) {
  using StatusValue = StatusValue<visualization::ViewPrimitive>;
  visualization::ViewPrimitive unpacked{
      .id = unpack(in.id()),
  };
  switch (in.payload_case()) {
    case ViewPrimitive::kSe3:
      unpacked.payload = unpack(in.se3());
      break;
    case ViewPrimitive::kDCurveSe3:
      unpacked.payload = unpack(in.d_curve_se3());
      break;
    default:
      return StatusValue{MAKE_STATUS("Can't unpack unset ViewPrimitive!")};
  }

  return StatusValue{unpacked};
}

}  // namespace detail

};  // namespace resim::visualization::proto