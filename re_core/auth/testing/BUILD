load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "mock_auth_server",
    testonly = 1,
    srcs = ["mock_auth_server.cc"],
    hdrs = ["mock_auth_server.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/assert",
        "//re_core/auth/proto:auth_messages_proto_cc",
        "//re_core/testing:mock_server",
        "//re_core/utils:http_response",
        "@com_google_protobuf//:protobuf",
    ],
)
