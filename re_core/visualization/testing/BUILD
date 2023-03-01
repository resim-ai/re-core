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

cc_library(
    name = "mock_server",
    testonly = True,
    srcs = ["mock_server.cc"],
    hdrs = ["mock_server.hh"],
    visibility = ["//re_core/visualization:__subpackages__"],
    deps = [
        "//re_core/utils:uuid",
        "//re_core/visualization:view_update",
        "//re_core/visualization/client/proto:view_client_proto_cc",
        "//re_core/visualization/proto:view_update_proto_cc",
        "//re_core/visualization/proto:view_update_to_proto",
        "@com_github_google_glog//:glog",
        "@fmt",
        "@httplib",
        "@libeigen//:eigen",
    ],
)

cc_test(
    name = "mock_server_test",
    srcs = ["mock_server_test.cc"],
    deps = [
        ":mock_server",
        ":test_helpers",
        "//re_core/transforms:se3",
        "//re_core/utils:uuid",
        "//re_core/visualization:view_primitive",
        "//re_core/visualization:view_update",
        "@com_google_googletest//:gtest_main",
        "@fmt",
    ],
)
