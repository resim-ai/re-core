load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("@rules_pkg//pkg:zip.bzl", "pkg_zip")

cc_binary(
    name = "resim_view_write_log",
    srcs = [
        "view_write_log.cc",
        "view_write_log_testing.cc",
    ],
    linkshared = True,
    deps = [
        ":view_write_log",
        ":view_write_log_testing",
    ],
)

