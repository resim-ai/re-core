# Copyright 2023 ReSim, Inc.
#
# Use of this source code is governed by an MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT.

load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "multivariate_gaussian",
    srcs = ["multivariate_gaussian.cc"],
    hdrs = ["multivariate_gaussian.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/assert",
        "@libeigen//:eigen",
    ],
)

cc_test(
    name = "multivariate_gaussian_test",
    srcs = ["multivariate_gaussian_test.cc"],
    deps = [
        ":multivariate_gaussian",
        ":sample_statistics",
        "//re_core/assert",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "sample_statistics",
    hdrs = ["sample_statistics.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/assert",
        "@libeigen//:eigen",
    ],
)

cc_test(
    name = "sample_statistics_test",
    srcs = ["sample_statistics_test.cc"],
    deps = [
        ":sample_statistics",
        "//re_core/assert",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "safe_integer_utils",
    srcs = ["safe_integer_utils.cc"],
    hdrs = ["safe_integer_utils.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/assert",
    ],
)

cc_test(
    name = "safe_integer_utils_test",
    srcs = ["safe_integer_utils_test.cc"],
    deps = [
        ":safe_integer_utils",
        "//re_core/assert",
        "@com_google_googletest//:gtest_main",
    ],
)
