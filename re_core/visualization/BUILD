load("@rules_cc//cc:defs.bzl", "cc_library")

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
