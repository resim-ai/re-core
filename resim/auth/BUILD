# Copyright 2023 ReSim, Inc.
#
# Use of this source code is governed by an MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT.

load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "auth_client_interface",
    hdrs = ["auth_client_interface.hh"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "device_code_client",
    srcs = ["device_code_client.cc"],
    hdrs = ["device_code_client.hh"],
    visibility = ["//visibility:public"],
    deps = [
        ":auth_client_interface",
        "//resim/assert",
        "//resim/auth/proto:auth_messages_proto_cc",
        "//resim/utils:http_response",
        "//resim/utils:inout",
        "@com_google_protobuf//:protobuf",
        "@cpr",
    ],
)

cc_test(
    name = "device_code_client_test",
    srcs = ["device_code_client_test.cc"],
    deps = [
        ":device_code_client",
        "//resim/assert",
        "//resim/auth/testing:mock_device_code_server",
        "//resim/testing:test_directory",
        "@com_google_googletest//:gtest_main",
    ],
)
