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
        "//resim_core/utils:uuid",
        "@com_github_google_glog//:glog",
    ],
)

cc_test(
    name = "uuid_to_proto_test",
    srcs = ["uuid_to_proto_test.cc"],
    deps = [
        ":uuid_proto_cc",
        ":uuid_to_proto",
        "//resim_core/utils:uuid",
        "@com_google_googletest//:gtest_main",
    ],
)
