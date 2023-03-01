load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@rules_pkg//pkg:mappings.bzl", "pkg_filegroup", "pkg_files", "strip_prefix")
load("@rules_pkg//pkg:zip.bzl", "pkg_zip")

cc_binary(
    name = "example_00_rigid_transform",
    srcs = ["example_00_rigid_transform.cc"],
    deps = [
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/visualization:view",
    ],
)

cc_binary(
    name = "example_01_framed_transform_composition",
    srcs = ["example_01_framed_transform_composition.cc"],
    deps = [
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/visualization:view",
    ],
)

# Package Rules to Create Demo Binary Package:

