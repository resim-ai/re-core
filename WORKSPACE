load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Gtest V 1.11
http_archive(
    name = "com_google_googletest",
    patch_args = ["-p1"],
    patches = ["//resim_core/third_party/googletest:googletest.patch"],
    sha256 = "ffa17fbc5953900994e2deec164bb8949879ea09b411e07f215bfbb1f87f4632",
    strip_prefix = "googletest-1.13.0",
    urls = ["https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip"],
)

# Eigen V 3.4.0
http_archive(
    name = "libeigen",
    build_file = "//resim_core/third_party/eigen:eigen.BUILD",
    sha256 = "1ccaabbfe870f60af3d6a519c53e09f3dcf630207321dffa553564a8e75c4fc8",
    strip_prefix = "eigen-3.4.0",
    urls = ["https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip"],
)

# Rules foreign CC
http_archive(
    name = "rules_foreign_cc",
    sha256 = "5303e3363fe22cbd265c91fce228f84cf698ab0f98358ccf1d95fba227b308f6",
    strip_prefix = "rules_foreign_cc-0.9.0",
    urls = ["https://github.com/bazelbuild/rules_foreign_cc/archive/refs/tags/0.9.0.zip"],
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

# lz4, which is a dependency for mcap
# zstd, which is a dependency for mcap
# Protobuf schemas for communications with foxglove
http_archive(
    name = "rules_python",
    sha256 = "cdf6b84084aad8f10bf20b46b77cb48d83c319ebe6458a18e9d2cebf57807cdd",
    strip_prefix = "rules_python-0.8.1",
    url = "https://github.com/bazelbuild/rules_python/archive/refs/tags/0.8.1.tar.gz",
)

load("@rules_python//python:repositories.bzl", "python_register_toolchains")

python_register_toolchains(
    name = "python3_10",
    # Available versions are listed in @rules_python//python:versions.bzl.
    # We recommend using the same version your team is already standardized on.
    python_version = "3.10",
)

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
http_archive(
    name = "hedron_compile_commands",
    sha256 = "8fd0e0c0b0c10dde492bb9fe8bc5c313c40333a7d7ea74891e211a6e680170aa",
    strip_prefix = "bazel-compile-commands-extractor-d3afb5dfadd4beca48bb027112d029f2d34ff0a0",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/d3afb5dfadd4beca48bb027112d029f2d34ff0a0.zip",
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()

# Protobuf
# rules_cc defines rules for generating C++ code from Protocol Buffers.
http_archive(
    name = "rules_proto",
    sha256 = "e017528fd1c91c5a33f15493e3a398181a9e821a804eb7ff5acdd1d2d6c2b18d",
    strip_prefix = "rules_proto-4.0.0-3.20.0",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0-3.20.0.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

# fmt string formatting library
http_archive(
    name = "fmt",
    build_file = "//resim_core/third_party/fmt:fmt.BUILD",
    sha256 = "cdc885473510ae0ea909b5589367f8da784df8b00325c55c7cbbab3058424120",
    strip_prefix = "fmt-9.1.0",
    urls = ["https://github.com/fmtlib/fmt/archive/refs/tags/9.1.0.zip"],
)

# bazel pkg rules
http_archive(
    name = "rules_pkg",
    sha256 = "eea0f59c28a9241156a47d7a8e32db9122f3d50b505fae0f33de6ce4d9b61834",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_pkg/releases/download/0.8.0/rules_pkg-0.8.0.tar.gz",
        "https://github.com/bazelbuild/rules_pkg/releases/download/0.8.0/rules_pkg-0.8.0.tar.gz",
    ],
)

load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")

rules_pkg_dependencies()

http_archive(
    name = "httplib",
    build_file = "//resim_core/third_party/httplib:httplib.BUILD",
    sha256 = "9d884bee50ded17de3a51d673bb9c2d7d11f101c595b0891830ba9d02e0cc368",
    strip_prefix = "cpp-httplib-0.11.4",
    urls = ["https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.11.4.zip"],
)

# Glog
http_archive(
    name = "com_github_gflags_gflags",
    sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
    strip_prefix = "gflags-2.2.2",
    urls = ["https://github.com/gflags/gflags/archive/v2.2.2.tar.gz"],
)

http_archive(
    name = "com_github_google_glog",
    sha256 = "122fb6b712808ef43fbf80f75c52a21c9760683dae470154f02bddfc61135022",
    strip_prefix = "glog-0.6.0",
    urls = ["https://github.com/google/glog/archive/v0.6.0.zip"],
)

# Polygon Mesh Processing (pmp) library. Used for loading, manipulating, and saving meshes.
# libccd - Used by fcl (below) for narrow-phase collision detection.
# Flexible Collision Library (fcl). Used for efficient broad-phase collision detection.
# Dependency for cxxopts below
http_archive(
    name = "rules_fuzzing",
    sha256 = "d9002dd3cd6437017f08593124fdd1b13b3473c7b929ceb0e60d317cb9346118",
    strip_prefix = "rules_fuzzing-0.3.2",
    urls = ["https://github.com/bazelbuild/rules_fuzzing/archive/v0.3.2.zip"],
)

load("@rules_fuzzing//fuzzing:repositories.bzl", "rules_fuzzing_dependencies")

rules_fuzzing_dependencies()

load("@rules_fuzzing//fuzzing:init.bzl", "rules_fuzzing_init")

rules_fuzzing_init()

http_archive(
    name = "cxxopts",
    sha256 = "25b644a2bfa9c6704d723be51b026bc02420dfdee1277a49bfe5df3f19b0eaa4",
    strip_prefix = "cxxopts-3.1.1",
    urls = ["https://github.com/jarro2783/cxxopts/archive/refs/tags/v3.1.1.zip"],
)

# Hedron's Bazel Rules for C++ HTTPS Requests
# Makes @cpr, @curl, and @boringssl available for use
# https://github.com/hedronvision/bazel-make-cc-https-easy
http_archive(
    name = "hedron_make_cc_https_easy",
    sha256 = "85488c2db684db127c867bb6b5a47e47f844140fc6c64047895d1d19c47e3006",
    strip_prefix = "bazel-make-cc-https-easy-f4f7512af5644f6f37e2270e0d36debad2bde45d",
    url = "https://github.com/hedronvision/bazel-make-cc-https-easy/archive/f4f7512af5644f6f37e2270e0d36debad2bde45d.tar.gz",
)

load("@hedron_make_cc_https_easy//:workspace_setup.bzl", "hedron_make_cc_https_easy")

hedron_make_cc_https_easy()

load("@hedron_make_cc_https_easy//:transitive_workspace_setup.bzl", "hedron_keep_cc_https_easy")

hedron_keep_cc_https_easy()
