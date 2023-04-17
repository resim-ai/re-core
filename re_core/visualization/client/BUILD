load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "view_client",
    srcs = ["view_client.cc"],
    hdrs = ["view_client.hh"],
    visibility = ["//visibility:public"],
    deps = [
        "//re_core/auth:auth_client_interface",
        "//re_core/auth:device_code_client",
        "//re_core/utils:status",
        "//re_core/visualization:view_client_interface",
        "//re_core/visualization/client/proto:view_client_proto_cc",
        "//re_core/visualization/proto:view_update_proto_cc",
        "//re_core/visualization/proto:view_update_to_proto",
        "@com_github_google_glog//:glog",
        "@cpr",
        "@fmt",
    ],
)
