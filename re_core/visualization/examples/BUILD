load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "hello",
    srcs = ["hello.cc"],
    deps = [
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/visualization:view",
    ],
)
