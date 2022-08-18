const { dlopen } = require("node:process");
const { constants } = require("node:os");
const { join } = require("node:path");

dlopen(module, join("./build/Release/hex-resolver.node"), constants.dlopen.RTLD_NOW);

module.exports;
