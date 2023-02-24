#pragma once

#include "re_core/actor/state/proto/trajectory.pb.h"
#include "re_core/actor/state/trajectory.hh"

namespace resim::actor::state::proto {

void pack(const actor::state::Trajectory &in, Trajectory *out);

actor::state::Trajectory unpack(const Trajectory &in);

}  // namespace resim::actor::state::proto
