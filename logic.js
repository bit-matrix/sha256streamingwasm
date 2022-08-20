const binding = require("./binding.js");

function sha256Finalizer(inp1, inp2) {
  return "1";
  // return binding.sha256Finalizer(inp1, inp2);
}

function sha256Updater(inp1, inp2) {
  return "2";
  // return binding.sha256Updater(inp1, inp2);
}

function sha256Initializer(inp1) {
  return "3";
  //  return binding.sha256Initializer(inp1);
}

exports.native = 2;
exports.sha256Finalizer = sha256Finalizer;
exports.sha256Updater = sha256Updater;
exports.sha256Initializer = sha256Initializer;
