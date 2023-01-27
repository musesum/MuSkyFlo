// swift-tools-version: 5.7

import PackageDescription

let package = Package(
    name: "MuSkyFlo",
    products: [
        .library(
            name: "MuSkyFlo",
            targets: ["MuSkyFlo"]),
    ],
    dependencies: [
    ],
    targets: [
        .target(
            name: "MuSkyFlo",
            dependencies: [],
            resources: [.process("Resources")]),
        .testTarget(
            name: "MuSkyFloTests",
            dependencies: ["MuSkyFlo"]),
    ]
)
