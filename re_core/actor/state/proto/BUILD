load("@rules_cc//cc:defs.bzl", "cc_library", "cc_proto_library", "cc_test")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "trajectory_proto",
    srcs = ["trajectory.proto"],
    deps = [
        "//re_core/curves/proto:t_curve_proto",
        "@com_google_protobuf//:timestamp_proto",
    ],
)

cc_proto_library(
    name = "trajectory_proto_cc",
    visibility = ["//visibility:public"],
    deps = [":trajectory_proto"],
)

cc_library(
    name = "trajectory_to_proto",
    srcs = ["trajectory_to_proto.cc"],
    hdrs = ["trajectory_to_proto.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":trajectory_proto_cc",
        "//re_core/actor/state:trajectory",
        "//re_core/curves/proto:t_curve_fse3_to_proto",
        "//re_core/time:timestamp",
        "//re_core/utils:inout",
        "@com_github_google_glog//:glog",
    ],
)

cc_test(
    name = "trajectory_to_proto_test",
    srcs = ["trajectory_to_proto_test.cc"],
    deps = [
        ":trajectory_to_proto",
        "//re_core/actor/state:trajectory",
        "//re_core/curves:t_curve",
        "//re_core/curves:t_curve_test_helpers",
        "//re_core/curves/proto:t_curve_fse3_to_proto",
        "//re_core/time:random_duration",
        "//re_core/time:timestamp",
        "@com_google_googletest//:gtest_main",
    ],
)
