load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Gtest V 1.11
http_archive(
    name = "com_google_googletest",
    sha256 = "8daa1a71395892f7c1ec5f7cb5b099a02e606be720d62f1a6a98f8f8898ec826",
    strip_prefix = "googletest-e2239ee6043f73722e7aa812a459f54a28552929",
    urls = ["https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip"],
)

# Eigen V 3.3.9
http_archive(
    name = "libeigen",
    build_file = "//resim_core/third_party/eigen:eigen.BUILD",
    sha256 = "83709a8def0d60dc4d17a749989893ea5e5aacf13f9184ae0509313f400f6f45",
    strip_prefix = "eigen-3.3.9",
    urls = ["https://gitlab.com/libeigen/eigen/-/archive/3.3.9/eigen-3.3.9.zip"],
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
    sha256 = "8603191949837cd01a91a0e78c32488d781de72bcbf455c9cca79ac03160c6de",
    strip_prefix = "bazel-compile-commands-extractor-d8ff4bd0142f70e0c51b11d6297e97b81136b018",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/d8ff4bd0142f70e0c51b11d6297e97b81136b018.tar.gz",
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
