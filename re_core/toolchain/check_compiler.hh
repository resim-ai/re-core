#pragma once

#include <string>

namespace re::toolchain {

struct CompilerData {
  std::string cpp_standard;
  std::string compiler_version;
};

CompilerData query_compiler_data() {
  return CompilerData{std::to_string(__cplusplus), __VERSION__};
}

}  // namespace re::toolchain
