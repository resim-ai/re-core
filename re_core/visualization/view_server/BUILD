load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("@rules_pkg//pkg:zip.bzl", "pkg_zip")

cc_library(
    name = "view_server_test_helper",
    testonly = 1,
    srcs = ["view_server_test_helper.cc"],
    hdrs = ["view_server_test_helper.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/actor/state:trajectory",
        "//re_core/curves:d_curve",
        "//re_core/curves:d_curve_test_helpers",
        "//re_core/curves:t_curve",
        "//re_core/curves:test_helpers",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:framed_vector",
        "//re_core/transforms:liegroup_test_helpers",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
    ],
)

cc_test(
    name = "view_server_test_helper_test",
    testonly = 1,
    srcs = ["view_server_test_helper_test.cc"],
    visibility = ["//visibility:public"],
    deps = [
        ":view_server_test_helper",
        "//re_core/actor/state:trajectory",
        "//re_core/assert",
        "//re_core/curves:d_curve",
        "//re_core/curves:d_curve_test_helpers",
        "//re_core/curves:t_curve",
        "//re_core/curves:test_helpers",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:liegroup_test_helpers",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "@com_google_googletest//:gtest_main",
    ],
)

