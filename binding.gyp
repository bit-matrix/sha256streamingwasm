{
    "targets": [{
        "target_name": "sha256Streaming",
        "cflags!": [ "-fno-exceptions" ],
        "cflags": [ "-std=c++11" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "./src/Bytestring.cpp",
            "./src/Bytestring.hpp",
            "./src/byteswap.h",
            "./src/common.h",
            "./src/cpuid.h",
            "./src/endian.h",
            "./src/sha256Streaming.cpp",
            "./src/sha256.cpp",
            "./src/sha256.h"
        ],

        "libraries": [],
 "conditions": [
        ["OS != 'mac' and OS != 'win'", {
          "cflags": [
            "-std=c99",
            "-Wcast-align",
            "-Wshadow"
          ]
        }],
        ["OS == 'mac'", {
          "xcode_settings": {
            "GCC_C_LANGUAGE_STANDARD": "c99",
            "WARNING_CFLAGS": [
              "-Wcast-align",
              "-Wshadow"
            ]
          }
        }],
        ["OS == 'win'", {
          "msvs_disabled_warnings=": [
            4244, # implicit integer demotion
            4267  # implicit size_t demotion
          ]
        }],
      ],

        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }]
}