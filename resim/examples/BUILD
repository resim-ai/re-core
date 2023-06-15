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
        "//resim/transforms:frame",
        "//resim/transforms:se3",
        "//resim/transforms:so3",
        "//resim/visualization:view",
    ],
)

cc_binary(
    name = "trajectory",
    srcs = ["trajectory.cc"],
    deps = [
        "//resim/actor/state:rigid_body_state",
        "//resim/actor/state:trajectory",
        "//resim/time:timestamp",
        "//resim/transforms:se3",
        "//resim/transforms:so3",
        "//resim/visualization:view",
        "@libeigen//:eigen",
    ],
)

cc_binary(
    name = "gaussian",
    srcs = ["gaussian.cc"],
    deps = [
        "//resim/math:multivariate_gaussian",
        "@fmt",
        "@libeigen//:eigen",
    ],
)

cc_binary(
    name = "time",
    srcs = ["time.cc"],
    deps = [
        "//resim/assert",
        "//resim/time:event_schedule",
        "//resim/time:sample_interval",
        "//resim/time:timestamp",
    ],
)
