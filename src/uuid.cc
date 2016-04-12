#include <uuid/uuid.h>
#include <node.h>
#include <v8.h>
#include <ctype.h>

#undef UUID_STR_LEN
#define UUID_STR_LEN 36
static inline void my_uuid_unparse_lower(uuid_t in, char *out) {
  int i;
  uuid_unparse(in, out);
  for(i=0;i<36;i++) out[i] = tolower(out[i]);
}

using namespace v8;
using namespace node;

void CreateUuid(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  uuid_t id;
  char uuid_str[37];

  uuid_generate(id);
  my_uuid_unparse_lower(id, uuid_str);

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, uuid_str));
}


void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "create", CreateUuid);
}
NODE_MODULE(uuid, init)
