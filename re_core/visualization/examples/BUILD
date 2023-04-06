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

cc_binary(
    name = "example_02_distance_parameterized_unit_circle",
    srcs = ["example_02_distance_parameterized_unit_circle.cc"],
    deps = [
        "//re_core/curves:d_curve",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/visualization:view",
    ],
)

cc_binary(
    name = "example_03_time_parameterized_closed_curve",
    srcs = ["example_03_time_parameterized_closed_curve.cc"],
    deps = [
        "//re_core/curves:t_curve",
        "//re_core/testing:random_matrix",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/visualization:view",
    ],
)

cc_binary(
    name = "example_04_actor_trajectory",
    srcs = ["example_04_actor_trajectory.cc"],
    deps = [
        "//re_core/actor/state:rigid_body_state",
        "//re_core/actor/state:trajectory",
        "//re_core/time:timestamp",
        "//re_core/transforms:frame",
        "//re_core/transforms:framed_group",
        "//re_core/transforms:se3",
        "//re_core/transforms:so3",
        "//re_core/utils:uuid",
        "//re_core/visualization:view",
    ],
)

# Package Rules to Create Demo Binary Package:

