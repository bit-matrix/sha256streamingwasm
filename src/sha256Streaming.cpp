
#include <node_api.h>


#ifndef NAPI_MODULE_INIT
#define NAPI_MODULE_INIT()                                        \
static napi_value sha256Streaming_init(napi_env env, napi_value exports); \
NAPI_MODULE(NODE_GYP_MODULE_NAME, sha256Streaming_init)                   \
static napi_value sha256Streaming_init(napi_env env, napi_value exports)
#endif

NAPI_MODULE_INIT() {
  size_t i;

  static const struct {
    const char *name;
    napi_callback callback;
  } funcs[] = {
#define F(name) { #name, sha256Streaming_ ## name }

#undef F
  };



  return exports;
}
