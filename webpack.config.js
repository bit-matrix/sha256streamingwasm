const path = require("path");

const NodePolyfillPlugin = require("node-polyfill-webpack-plugin");

module.exports = (env) => {
  // eslint-disable-next-line no-console
  // console.log(env.mod);

  return {
    // mode: env.mod,
    entry: {
      sha256straming: "./index.js",
    },
    output: {
      filename: "index.js",
      library: "[name]",
      libraryTarget: "commonjs2",
    },
    target: "node",
    node: {
      __dirname: false,
    },
    devtool: "source-map", // devtool: 'cheap-module-source-map',
    module: {
      rules: [
        {
          test: /\.js$/,
          exclude: /node_modules/,
          loader: "babel-loader",
        },
        {
          test: /\.node$/,
          loader: "node-loader",
        },
      ],
    },
    resolve: {
      extensions: [".js", ".node"],
    },

    plugins: [new NodePolyfillPlugin()],
  };
};
