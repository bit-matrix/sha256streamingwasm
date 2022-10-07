//
//  main.cpp
//  sha256context
//
//  Created by Burak on 16.08.2022.
//

#include <napi.h>
#include <iostream>
#include "sha256.h"
#include <sstream>
#include "Bytestring.hpp"
#include <vector>
#include "endian.h"

using namespace Napi;

std::string sha256Finalize(std::string in1, std::string in2)
{

    ByteString bs(in1);
    std::string s1 = bs.fromHexString();

    std::vector<unsigned char> t1;
    t1.insert(t1.begin(), s1.begin(), s1.end());

    ByteString bs2(in2);
    std::string s2 = bs2.fromHexString();
    const unsigned char *t2 = reinterpret_cast<const unsigned char *>(s2.c_str());

    CSHA256 cs;

    cs.Load(t1);
    cs.SafeWrite(t2, s2.size());

    std::vector<unsigned char> result(32);

    cs.Finalize(result.data());

    std::string string;

    char const hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < result.size(); ++i)
    {
        char const byte = result[i];

        string += hex_chars[(byte & 0xF0) >> 4];
        string += hex_chars[(byte & 0x0F) >> 0];
    }

    return string;
}

std::string sha256Update(std::string in1, std::string in2)
{

    ByteString bs(in1);
    std::string s1 = bs.fromHexString();

    std::vector<unsigned char> t1;
    t1.insert(t1.begin(), s1.begin(), s1.end());

    ByteString bs2(in2);
    std::string s2 = bs2.fromHexString();
    const unsigned char *t2 = reinterpret_cast<const unsigned char *>(s2.c_str());

    CSHA256 cs;

    cs.Load(t1);
    cs.SafeWrite(t2, s2.size());

    std::vector<unsigned char> l;
    l = cs.Save();

    std::string string;

    char const hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < l.size(); ++i)
    {
        char const byte = l[i];

        string += hex_chars[(byte & 0xF0) >> 4];
        string += hex_chars[(byte & 0x0F) >> 0];
    }

    return string;
}

std::string sha256Initialize(std::string in)
{

    ByteString bs(in);
    std::string s = bs.fromHexString();

    const unsigned char *t = reinterpret_cast<const unsigned char *>(s.c_str());

    CSHA256 cs;
    cs.SafeWrite(t, s.size());

    std::vector<unsigned char> l;
    l = cs.Save();

    std::string string;

    char const hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < l.size(); ++i)
    {
        char const byte = l[i];

        string += hex_chars[(byte & 0xF0) >> 4];
        string += hex_chars[(byte & 0x0F) >> 0];
    }

    return string;
}

int deterministicrandom(int intMax, int intMin, std::string entropy){
    
    ByteString bs(entropy);
    std::string s1 = bs.fromHexString();
    
    std::vector<unsigned char> t1;
    t1.insert(t1.begin(), s1.begin(), s1.end());
    

    uint64_t nMax = (intMax - intMin);
    uint64_t nRange = (std::numeric_limits<uint64_t>::max() / nMax) * nMax;
    uint64_t nRand;
    
    
    std::vector<unsigned char> vchHash(32, 0);
    uint64_t nCounter = 0;
    int nHashIndex = 3;
    
    CSHA256 hasher;
    hasher.Write(t1.data(), t1.size());
    
    do {
        if (nHashIndex >= 3) {
            uint64_t le_counter = htole64(nCounter);
            CSHA256(hasher).Write((const unsigned char*)&le_counter, sizeof(nCounter)).Finalize(vchHash.data());
                nHashIndex = 0;
                nCounter++;
        }

            nRand = 0;
        for (size_t i=0; i<8; ++i)
                nRand |= ((uint64_t)vchHash[(nHashIndex*8) + i]) << (8*i);

                nHashIndex++;
        } while (nRand > nRange);
    
    int result(nRand % nMax);
    result += intMin;
    
    
    
    return result;
}

String Sha256Finalize(const CallbackInfo &info)
{
    Env env = info.Env();
    std::string str1 = info[0].As<String>().Utf8Value();
    std::string str2 = info[1].As<String>().Utf8Value();
    String returnValue = String::New(env, sha256Finalize(str1, str2));

    return returnValue;
}

String Sha256Update(const CallbackInfo &info)
{
    Env env = info.Env();
    std::string str1 = info[0].As<String>().Utf8Value();
    std::string str2 = info[1].As<String>().Utf8Value();
    String returnValue = String::New(env, sha256Update(str1, str2));

    return returnValue;
}

String Sha256Initialize(const CallbackInfo &info)
{
    Env env = info.Env();
    std::string str1 = info[0].As<String>().Utf8Value();
    String returnValue = String::New(env, sha256Initialize(str1));

    return returnValue;
}

Number DeterministicRandom(const CallbackInfo &info)
{
    Env env = info.Env();
    int intMax = info[0].As<Number>().Uint32Value();
    int intMin = info[1].As<Number>().Uint32Value();
    std::string entropy = info[2].As<String>().Utf8Value();
    Number returnValue = Number::New(env, deterministicrandom(intMax,intMin,entropy));

    return returnValue;
}

Object InitAll(Env env, Object exports)
{
    exports.Set("sha256Finalizer", Function::New(env, Sha256Finalize));
    exports.Set("sha256Updater", Function::New(env, Sha256Update));
    exports.Set("sha256Initializer", Function::New(env, Sha256Initialize));
    exports.Set("deterministicrandom", Function::New(env, DeterministicRandom));

    return exports;
}

NODE_API_MODULE(Sha256Stream, InitAll);
