#pragma once

#include "re_core/transforms/frame.hh"
#include "re_core/transforms/proto/frame_3.pb.h"

namespace resim::transforms::proto {

void pack(const transforms::Frame<3> &in, Frame_3 *out);

transforms::Frame<3> unpack(const Frame_3 &in);

};  // namespace resim::transforms::proto