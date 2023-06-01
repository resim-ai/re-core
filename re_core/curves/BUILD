load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

exports_files(
    [
        "quintic_poly_coeffs.hh",
        "t_curve.hh",
        "t_curve_segment.hh",
        "two_jet.hh",
        "two_jet_concepts.hh",
        "d_curve.hh",
        "quintic_poly_coeffs.cc",
        "t_curve.cc",
        "t_curve_segment.cc",
        "two_jet.cc",
        "two_jet_concepts.cc",
        "d_curve.cc",
    ],
)

cc_library(
    name = "d_curve",
    srcs = ["d_curve.cc"],
    hdrs = ["d_curve.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/assert",
        "//re_core/transforms:se3",
    ],
)

cc_library(
    name = "d_curve_test_helpers",
    testonly = 1,
    srcs = ["d_curve_test_helpers.cc"],
    hdrs = ["d_curve_test_helpers.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":d_curve",
        "//re_core/assert",
        "//re_core/transforms:frame",
        "//re_core/transforms:liegroup_concepts",
        "//re_core/transforms:se3",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "d_curve_test",
    srcs = ["d_curve_test.cc"],
    deps = [
        ":d_curve",
        ":d_curve_test_helpers",
        "//re_core/assert",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "quintic_poly_coeffs",
    srcs = ["quintic_poly_coeffs.cc"],
    hdrs = ["quintic_poly_coeffs.hh"],
)

cc_test(
    name = "quintic_poly_coeffs_test",
    srcs = ["quintic_poly_coeffs_test.cc"],
    deps = [
        ":quintic_poly_coeffs",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "t_curve",
    srcs = ["t_curve.cc"],
    hdrs = ["t_curve.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":t_curve_segment",
        ":two_jet",
        "//re_core/assert",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:framed_group_concept",
        "//re_core/transforms:liegroup_concepts",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/utils:inout",
    ],
)

cc_test(
    name = "t_curve_test",
    srcs = ["t_curve_test.cc"],
    deps = [
        ":t_curve",
        ":t_curve_test_helpers",
        ":two_jet",
        "//re_core/assert",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:framed_group_concept",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "t_curve_segment",
    srcs = ["t_curve_segment.cc"],
    hdrs = ["t_curve_segment.hh"],
    deps = [
        ":quintic_poly_coeffs",
        ":two_jet",
        "//re_core/assert",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:framed_group_concept",
        "//re_core/transforms:liegroup_concepts",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/utils:inout",
    ],
)

cc_test(
    name = "t_curve_segment_test",
    srcs = ["t_curve_segment_test.cc"],
    deps = [
        ":t_curve_segment",
        ":two_jet",
        "//re_core/assert",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:framed_group_concept",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "two_jet",
    srcs = ["two_jet.cc"],
    hdrs = ["two_jet.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":two_jet_concepts",
        "//re_core/transforms:liegroup_concepts",
        "//re_core/transforms:se3",
    ],
)

cc_test(
    name = "two_jet_test",
    srcs = ["two_jet_test.cc"],
    deps = [
        ":two_jet",
        ":two_jet_concepts",
        ":two_jet_test_helpers",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:liegroup_concepts",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "two_jet_concepts",
    hdrs = ["two_jet_concepts.hh"],
    deps = [
        "//re_core/transforms:liegroup_concepts",
    ],
)

cc_test(
    name = "two_jet_concepts_test",
    srcs = ["two_jet_concepts_test.cc"],
    deps = [
        ":two_jet",
        ":two_jet_concepts",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "two_jet_test_helpers",
    testonly = 1,
    srcs = ["two_jet_test_helpers.cc"],
    hdrs = ["two_jet_test_helpers.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":two_jet",
        ":two_jet_concepts",
        "//re_core/assert",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:liegroup_test_helpers",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
    ],
)

cc_test(
    name = "two_jet_test_helpers_test",
    srcs = ["two_jet_test_helpers_test.cc"],
    deps = [
        ":two_jet_test_helpers",
        "//re_core/assert",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "t_curve_test_helpers",
    testonly = 1,
    srcs = ["t_curve_test_helpers.cc"],
    hdrs = ["t_curve_test_helpers.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":t_curve",
        ":two_jet",
        ":two_jet_test_helpers",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:framed_group_concept",
        "//re_core/transforms:liegroup_concepts",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "@com_github_google_glog//:glog",
    ],
)

cc_test(
    name = "t_curve_test_helpers_test",
    srcs = ["t_curve_test_helpers_test.cc"],
    deps = [
        ":t_curve",
        ":t_curve_test_helpers",
        ":two_jet",
        ":two_jet_test_helpers",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "test_helpers",
    testonly = True,
    srcs = ["test_helpers.cc"],
    hdrs = ["test_helpers.hh"],
    visibility = ["//re_core:__subpackages__"],
    deps = [
        ":t_curve",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "@libeigen//:eigen",
    ],
)

cc_test(
    name = "test_helpers_test",
    srcs = ["test_helpers_test.cc"],
    deps = [
        ":test_helpers",
        "//re_core/curves:t_curve",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "@com_google_googletest//:gtest_main",
        "@libeigen//:eigen",
    ],
)
