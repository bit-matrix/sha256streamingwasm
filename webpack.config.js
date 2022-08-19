const os = require("os");
const CopyWebpackPlugin = require("copy-webpack-plugin");

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
          options: {
            flags: os.constants.dlopen.RTLD_NOW,
          },
        },
      ],
    },
    resolve: {
      extensions: [".js", ".node"],
    },

    plugins: [
      new CopyWebpackPlugin({
        patterns: [
          {
            from: "build/Release/hex-resolver.node",
            to: "dist",
          },
        ],
      }),
    ],
  };
};
