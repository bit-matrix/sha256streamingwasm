cmd_Release/hex-resolver.node := c++ -bundle -undefined dynamic_lookup -Wl,-search_paths_first -mmacosx-version-min=10.7 -arch arm64 -L./Release -stdlib=libc++  -o Release/hex-resolver.node Release/obj.target/hex-resolver/Bytestring.o Release/obj.target/hex-resolver/hex-resolver.o Release/obj.target/hex-resolver/sha256.o Release/nothing.a 
