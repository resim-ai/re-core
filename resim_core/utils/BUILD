load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

exports_files(
    [
        "inout.hh",
        "uuid.hh",
        "inout.cc",
        "uuid.cc",
    ],
)

cc_library(
    name = "uuid",
    srcs = ["uuid.cc"],
    hdrs = ["uuid.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//resim_core/assert",
    ],
)

cc_test(
    name = "uuid_test",
    srcs = ["uuid_test.cc"],
    deps = [
        ":uuid",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "inout",
    hdrs = ["inout.hh"],
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_test(
    name = "inout_test",
    srcs = ["inout_test.cc"],
    deps = [
        ":inout",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "type",
    hdrs = ["type.hh"],
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_test(
    name = "type_test",
    srcs = ["type_test.cc"],
    deps = [
        ":type",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "match",
    hdrs = ["match.hh"],
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_test(
    name = "match_test",
    srcs = ["match_test.cc"],
    deps = [
        ":match",
        "//resim_core/testing:move_copy_tracker",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "nullable_reference",
    hdrs = ["nullable_reference.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//resim_core/assert",
    ],
)

cc_test(
    name = "nullable_reference_test",
    srcs = ["nullable_reference_test.cc"],
    deps = [
        ":nullable_reference",
        "//resim_core/assert",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "status",
    srcs = ["status.cc"],
    hdrs = ["status.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":match",
        "//resim_core/assert",
        "@fmt",
    ],
)

cc_test(
    name = "status_test",
    srcs = ["status_test.cc"],
    deps = [
        ":status",
        "//resim_core/assert",
        "@com_google_googletest//:gtest_main",
        "@fmt",
    ],
)

cc_library(
    name = "status_value",
    hdrs = ["status_value.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":match",
        ":status",
        "//resim_core/assert",
    ],
)

cc_test(
    name = "status_value_test",
    srcs = ["status_value_test.cc"],
    deps = [
        ":status_value",
        "//resim_core/assert",
        "//resim_core/testing:move_copy_tracker",
        "@com_google_googletest//:gtest_main",
    ],
)
