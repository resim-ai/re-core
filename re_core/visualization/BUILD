load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "view_primitive",
    hdrs = ["view_primitive.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/transforms:se3",
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
    name = "view_client",
    hdrs = ["view_client.hh"],
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
        ":view_client",
        ":view_primitive",
        ":view_update",
        "//re_core/utils:status",
        "//re_core/utils:uuid",
        "//re_core/visualization/client:view_client_libcurl",
        "@com_google_googletest//:gtest_prod",
    ],
)

cc_test(
    name = "view_test",
    srcs = ["view_test.cc"],
    deps = [
        ":view",
        ":view_client",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:liegroup_test_helpers",
        "//re_core/transforms:se3",
        "//re_core/utils:status",
        "//re_core/visualization/client:view_client_libcurl",
        "//re_core/visualization/testing:mock_server",
        "@com_google_googletest//:gtest_main",
    ],
)
