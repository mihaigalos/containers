load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

DEFAULT_COMPILER_OPTIONS = [
    "-DLOGGING",
    "-DTESTING",
    "-fdiagnostics-color",
    "-std=c++14",
    "-Wall",
    "-Werror",
    "-Wextra",
    "-Wpedantic",
]

DEFAULT_TEST_DEPS = [
    ":sources",
    "@gtest",
    "@gtest//:gtest_main",
]

cc_library(
    name = "sources",
    srcs = glob(
        ["src/**/*.cpp"],
        exclude = ["src/avr_main.cpp"],
    ),
    hdrs = glob(["include/**/*.h"]),
    copts = DEFAULT_COMPILER_OPTIONS,
    strip_include_prefix = "include",
)

cc_library(
    name = "test_headers",
    hdrs = glob(["test/**/*.h"]),
    copts = DEFAULT_COMPILER_OPTIONS,
    strip_include_prefix = "test/unit",
)

[
    cc_test(
        name = "unit/" + unit_name,
        srcs = [
            "test/unit/" + unit_name + ".cpp",
        ],
        copts = DEFAULT_COMPILER_OPTIONS,
        tags = ["unit"],
        deps = DEFAULT_TEST_DEPS + [":test_headers"],
    )
    for unit_name in [
        file_name.replace("test/unit/", "").replace(".cpp", "")
        for file_name in glob(["test/unit/**/*.cpp"])
    ]
]
