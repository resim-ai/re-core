#include <glog/logging.h>
#include <gtest/gtest.h>

namespace re::third_party::glog {

// Ensure glog is installed and linked.
TEST(GlogTest, WriteSomeOutput) { LOG(INFO) << "Glog working successfully."; }

}  // namespace re::third_party::glog
