load("//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")
load("@build_bazel_rules_nodejs//:index.bzl", "nodejs_test")

config_setting(
    name = "emsc",
    values = {
        "cpu": "wasm",
    },
)

cc_test(
    name = "embed-file",
    srcs = ["embed-file.cc"],
    linkopts = select({
        ":emsc": ["--embed-file", "$(rootpath fox.txt)"],
        "//conditions:default": [],
    }),
    data = ["fox.txt"],
)

wasm_cc_binary(
    name = "embed-file-wasm",
    cc_target = ":embed-file",
    testonly = True,
)

nodejs_test(
    name = "embed-file-node",
    data = ["embed-file-wasm"],
    entry_point = ":embed-file-wasm/embed-file.js",
)


