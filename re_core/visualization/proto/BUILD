load("@rules_cc//cc:defs.bzl", "cc_library", "cc_proto_library", "cc_test")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "view_primitive_proto",
    srcs = ["view_primitive.proto"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/curves/proto:d_curve_proto",
        "//re_core/curves/proto:t_curve_proto",
        "//re_core/transforms/proto:fse3_proto",
        "//re_core/transforms/proto:se3_proto",
        "//re_core/transforms/proto:so3_proto",
        "//re_core/utils/proto:uuid_proto",
    ],
)

cc_proto_library(
    name = "view_primitive_proto_cc",
    visibility = ["//visibility:public"],
    deps = [
        ":view_primitive_proto",
    ],
)

cc_library(
    name = "view_primitive_to_proto",
    srcs = ["view_primitive_to_proto.cc"],
    hdrs = ["view_primitive_to_proto.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":view_primitive_proto_cc",
        "//re_core/assert",
        "//re_core/curves:d_curve",
        "//re_core/curves:t_curve",
        "//re_core/curves/proto:d_curve_fse3_to_proto",
        "//re_core/curves/proto:d_curve_se3_to_proto",
        "//re_core/curves/proto:t_curve_fse3_to_proto",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/transforms/proto:fse3_to_proto",
        "//re_core/transforms/proto:se3_to_proto",
        "//re_core/transforms/proto:so3_to_proto",
        "//re_core/utils:match",
        "//re_core/utils:status_value",
        "//re_core/utils/proto:uuid_to_proto",
        "//re_core/visualization:view_primitive",
    ],
)

cc_test(
    name = "view_primitive_to_proto_test",
    srcs = ["view_primitive_to_proto_test.cc"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/assert",
        "//re_core/curves:d_curve",
        "//re_core/curves:t_curve",
        "//re_core/curves/proto:d_curve_fse3_to_proto",
        "//re_core/curves/proto:d_curve_se3_to_proto",
        "//re_core/curves/proto:t_curve_fse3_to_proto",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:liegroup_test_helpers",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/transforms/proto:fse3_to_proto",
        "//re_core/transforms/proto:se3_to_proto",
        "//re_core/transforms/proto:so3_to_proto",
        "//re_core/utils:match",
        "//re_core/utils:uuid",
        "//re_core/utils/proto:uuid_proto_cc",
        "//re_core/utils/proto:uuid_to_proto",
        "//re_core/visualization:view_primitive",
        "//re_core/visualization/curve:test_helpers",
        "//re_core/visualization/proto:view_primitive_proto_cc",
        "//re_core/visualization/proto:view_primitive_to_proto",
        "@com_google_googletest//:gtest_main",
    ],
)

proto_library(
    name = "view_update_proto",
    srcs = ["view_update.proto"],
    visibility = ["//visibility:public"],
    deps = [
        ":view_primitive_proto",
        "//re_core/utils/proto:uuid_proto",
    ],
)

cc_proto_library(
    name = "view_update_proto_cc",
    visibility = ["//visibility:public"],
    deps = [
        ":view_update_proto",
    ],
)

cc_library(
    name = "view_update_to_proto",
    srcs = ["view_update_to_proto.cc"],
    hdrs = ["view_update_to_proto.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":view_primitive_to_proto",
        "//re_core/assert",
        "//re_core/visualization:view_update",
        "//re_core/visualization/proto:view_update_proto_cc",
    ],
)

cc_test(
    name = "view_update_to_proto_test",
    srcs = ["view_update_to_proto_test.cc"],
    deps = [
        ":view_primitive_to_proto",
        ":view_update_to_proto",
        "//re_core/assert",
        "//re_core/transforms:se3",
        "//re_core/utils:match",
        "//re_core/utils:uuid",
        "//re_core/visualization:view_primitive",
        "//re_core/visualization/testing:test_helpers",
        "@com_google_googletest//:gtest_main",
    ],
)
