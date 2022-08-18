{
    "targets": [{
        "target_name": "hex-resolver",
        "cflags!": [ "-fno-exceptions" ],
        "cflags": [ "-std=c++11" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "Bytestring.cpp",
            "Bytestring.hpp",
            "byteswap.h",
            "common.h",
            "cpuid.h",
            "endian.h",
            "hex-resolver.cpp",
            "sha256.cpp",
            "sha256.h"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
        ],
        "libraries": [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")",
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        "conditions": [
        ["OS != 'mac' and OS != 'win'", {
          "cflags": [
            "-std=c89",
            "-pedantic",
            "-Wcast-align",
            "-Wno-implicit-fallthrough",
            "-Wno-long-long",
            "-Wno-overlength-strings",
            "-Wshadow"
          ]
        }],
        ["OS == 'mac'", {
          "xcode_settings": {
            "MACOSX_DEPLOYMENT_TARGET": "10.7",
            "GCC_C_LANGUAGE_STANDARD": "c89",
            "WARNING_CFLAGS": [
              "-pedantic",
              "-Wcast-align",
              "-Wno-implicit-fallthrough",
              "-Wno-long-long",
              "-Wno-overlength-strings",
              "-Wshadow"
            ]
          }
        }],
        ["OS == 'win'", {
          "msvs_disabled_warnings=": [
            4146, # negation of unsigned integer
            4244, # implicit integer demotion
            4267, # implicit size_t demotion
            4334  # implicit 32->64 bit shift
          ]
        }],
      ]
    }]
}