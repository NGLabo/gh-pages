const path = require("path");
const CopyPlugin = require("copy-webpack-plugin");

const output = path.join(__dirname, "build");

module.exports = {
  devServer: {
    contentBase: output,
    port: 3000,
  },
  entry: "./src/Index.bs.js",
  mode: process.env.NODE_ENV === "production" ? "production" : "development",
  module: {
    rules: [
      {
        test: /\.css$/,
        use: ["style-loader", "css-loader"],
      },
      {
        test: /\.(woff|woff2)$/,
        type: "asset/resource",
      },
    ],
  },
  output: {
    filename: "Index.bs.js",
    path: output,
  },
  plugins: [
    new CopyPlugin({
      patterns: [{ from: "public" }],
    }),
  ],
};
