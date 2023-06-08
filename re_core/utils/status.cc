#include "re_core/utils/status.hh"

#include "re_core/utils/match.hh"

namespace re {

std::string Status::what() const {
  return match(
      status_,
      [](const OkayType &status) -> std::string {
        return OkayType::MESSAGE.data();
      },
      [](const ErrType &status) -> std::string {
        return fmt::format(
            "<{0}:{1}> {2}",
            status.file,
            status.line,
            status.message);
      });
}

}  // namespace re
