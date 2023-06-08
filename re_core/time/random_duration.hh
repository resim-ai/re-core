#pragma once

#include <random>

#include "re_core/time/timestamp.hh"
#include "re_core/utils/inout.hh"

namespace re::time {

// Generate a uniformly random timestamp with the given random number
// generator.
// @param[in] rng - The random number generator to use to generate
//                  results.
template <typename RNG>
Duration random_duration(InOut<RNG> rng) {
  std::uniform_int_distribution dist{
      std::numeric_limits<int64_t>::min(),
      std::numeric_limits<int64_t>::max()};
  return Duration{dist(*rng)};
}

}  // namespace re::time
