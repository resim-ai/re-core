
#include "re_core/testing/test_directory.hh"

#include <glog/logging.h>

#include "re_core/utils/uuid.hh"

namespace resim::testing {

namespace fs = std::filesystem;

TestDirectoryRAII::TestDirectoryRAII()
    : path_{fs::temp_directory_path() / UUID::new_uuid().to_string()} {
  const bool cond = fs::create_directory(path_);
  CHECK(cond) << "Failed to make directory!";
}

TestDirectoryRAII::~TestDirectoryRAII() {
  const bool cond = fs::remove_all(path_) != 0U;
  CHECK(cond) << "Failed to remove directory!";
}

const fs::path &TestDirectoryRAII::path() const { return path_; }

fs::path TestDirectoryRAII::test_file_path(
    const std::string_view &extension) const {
  if (extension.empty()) {
    return path_ / UUID::new_uuid().to_string();
  }
  return path_ / (UUID::new_uuid().to_string() + ".").append(extension);
}

}  // namespace resim::testing
