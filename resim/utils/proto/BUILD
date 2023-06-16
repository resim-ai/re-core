# Copyright 2023 ReSim, Inc.
#
# Use of this source code is governed by an MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT.

load("@rules_cc//cc:defs.bzl", "cc_library", "cc_proto_library", "cc_test")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "uuid_proto",
    srcs = ["uuid.proto"],
    visibility = ["//visibility:public"],
)

cc_proto_library(
    name = "uuid_proto_cc",
    visibility = ["//visibility:public"],
    deps = [":uuid_proto"],
)

cc_library(
    name = "uuid_to_proto",
    srcs = ["uuid_to_proto.cc"],
    hdrs = ["uuid_to_proto.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":uuid_proto_cc",
        "//resim/assert",
        "//resim/utils:uuid",
    ],
)

cc_test(
    name = "uuid_to_proto_test",
    srcs = ["uuid_to_proto_test.cc"],
    deps = [
        ":uuid_proto_cc",
        ":uuid_to_proto",
        "//resim/assert",
        "//resim/utils:uuid",
        "@com_google_googletest//:gtest_main",
    ],
)
