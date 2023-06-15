load("@rules_cc//cc:defs.bzl", "cc_binary")


cc_binary(
  name = "assert_and_status",
  srcs = ["assert_and_status.cc"],
  deps = [
    "//resim/assert",
    "//resim/utils:status",
    "//resim/utils:status_value",
  ],
)

cc_binary(
  name = "curves",
  srcs = ["curves.cc"],
  deps = [
    "//resim/assert",
    "//resim/curves:d_curve",
    "//resim/curves:t_curve",
    "//resim/curves:two_jet",
    "//resim/transforms:se3",
    "//resim/transforms:so3",
    "//resim/transforms:frame",
    "//resim/visualization:view",
  ],
)
