load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

exports_files([
    "view.hh",
    "view_primitive.hh",
    "view.cc",
])

cc_library(
    name = "view_primitive",
    hdrs = ["view_primitive.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/actor/state:trajectory",
        "//re_core/curves:d_curve",
        "//re_core/curves:t_curve",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:framed_vector",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/utils:uuid",
    ],
)

cc_library(
    name = "view_update",
    hdrs = ["view_update.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":view_primitive",
    ],
)

cc_library(
    name = "view_client_interface",
    hdrs = ["view_client_interface.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":view_update",
        "//re_core/utils:status",
    ],
)

cc_library(
    name = "view",
    srcs = ["view.cc"],
    hdrs = ["view.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":view_client_interface",
        ":view_primitive",
        ":view_update",
        "//re_core/assert",
        "//re_core/curves:d_curve",
        "//re_core/curves:t_curve",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/utils:status",
        "//re_core/utils:uuid",
        "//re_core/visualization/client:view_client",
        "@com_google_googletest//:gtest_prod",
    ],
)

cc_test(
    name = "view_test",
    srcs = ["view_test.cc"],
    deps = [
        ":view",
        ":view_client_interface",
        "//re_core/actor/state:trajectory",
        "//re_core/assert",
        "//re_core/auth/testing:mock_auth_client",
        "//re_core/curves:d_curve",
        "//re_core/curves:t_curve",
        "//re_core/curves:test_helpers",
        "//re_core/testing:test_directory",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:framed_vector",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/utils:http_response",
        "//re_core/utils:match",
        "//re_core/utils:status",
        "//re_core/visualization/client:view_client",
        "//re_core/visualization/testing:mock_server",
        "//re_core/visualization/view_server:view_server_test_helper",
        "@com_github_google_glog//:glog",
        "@com_google_googletest//:gtest_main",
    ],
)
