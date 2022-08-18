const { dlopen } = require("node:process");
const { join } = require("node:path");

dlopen(module, join("./build/Release/hex-resolver.node"));

module.exports;
