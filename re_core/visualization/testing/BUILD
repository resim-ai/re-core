load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "test_helpers",
    testonly = True,
    srcs = ["test_helpers.cc"],
    hdrs = ["test_helpers.hh"],
    visibility = ["//re_core/visualization:__subpackages__"],
    deps = [
        "//re_core/transforms:se3",
        "//re_core/utils:match",
        "//re_core/visualization:view_primitive",
    ],
)

cc_test(
    name = "test_helpers_test",
    srcs = ["test_helpers_test.cc"],
    deps = [
        ":test_helpers",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:se3",
        "//re_core/utils:uuid",
        "//re_core/visualization:view_primitive",
        "@com_google_googletest//:gtest_main",
    ],
)
