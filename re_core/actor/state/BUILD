load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "rigid_body_state",
    srcs = ["rigid_body_state.cc"],
    hdrs = ["rigid_body_state.hh"],
    deps = [
        "//re_core/curves:two_jet",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:liegroup_concepts",
        "//re_core/transforms:se3",
        "@libeigen//:eigen",
    ],
)

cc_test(
    name = "rigid_body_state_test",
    srcs = ["rigid_body_state_test.cc"],
    deps = [
        ":rigid_body_state",
        "//re_core/curves:two_jet",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:liegroup_concepts",
        "//re_core/transforms:se3",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "trajectory",
    srcs = ["trajectory.cc"],
    hdrs = ["trajectory.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":rigid_body_state",
        "//re_core/curves:t_curve",
        "//re_core/curves:two_jet",
        "//re_core/time:timestamp",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "@libeigen//:eigen",
    ],
)

cc_test(
    name = "trajectory_test",
    srcs = ["trajectory_test.cc"],
    deps = [
        ":rigid_body_state",
        ":trajectory",
        "//re_core/curves:t_curve",
        "//re_core/curves:two_jet",
        "//re_core/testing:random_matrix",
        "//re_core/time:timestamp",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "@com_google_googletest//:gtest_main",
    ],
)
