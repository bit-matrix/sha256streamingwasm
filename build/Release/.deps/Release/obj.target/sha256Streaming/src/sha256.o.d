cmd_Release/obj.target/sha256Streaming/src/sha256.o := c++ -o Release/obj.target/sha256Streaming/src/sha256.o ../src/sha256.cpp '-DNODE_GYP_MODULE_NAME=sha256Streaming' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-DV8_DEPRECATION_WARNINGS' '-DV8_IMMINENT_DEPRECATION_WARNINGS' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DNAPI_DISABLE_CPP_EXCEPTIONS' '-DBUILDING_NODE_EXTENSION' -I/Users/afarukcali/Library/Caches/node-gyp/16.15.0/include/node -I/Users/afarukcali/Library/Caches/node-gyp/16.15.0/src -I/Users/afarukcali/Library/Caches/node-gyp/16.15.0/deps/openssl/config -I/Users/afarukcali/Library/Caches/node-gyp/16.15.0/deps/openssl/openssl/include -I/Users/afarukcali/Library/Caches/node-gyp/16.15.0/deps/uv/include -I/Users/afarukcali/Library/Caches/node-gyp/16.15.0/deps/zlib -I/Users/afarukcali/Library/Caches/node-gyp/16.15.0/deps/v8/include  -O3 -gdwarf-2 -mmacosx-version-min=10.13 -arch arm64 -Wall -Wendif-labels -W -Wno-unused-parameter -Wcast-align -Wshadow -std=gnu++14 -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing -MMD -MF ./Release/.deps/Release/obj.target/sha256Streaming/src/sha256.o.d.raw   -c
Release/obj.target/sha256Streaming/src/sha256.o: ../src/sha256.cpp \
  ../src/sha256.h ../src/common.h ../src/endian.h ../src/byteswap.h \
  ../src/cpuid.h
../src/sha256.cpp:
../src/sha256.h:
../src/common.h:
../src/endian.h:
../src/byteswap.h:
../src/cpuid.h:
