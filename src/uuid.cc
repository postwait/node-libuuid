#include <uuid/uuid.h>
#include <nan.h>

#undef UUID_STR_LEN
#define UUID_STR_LEN 36
static inline void my_uuid_unparse_lower(uuid_t in, char *out) {
  int i;
  uuid_unparse(in, out);
  for(i=0;i<36;i++) out[i] = tolower(out[i]);
}

using v8::FunctionTemplate;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_METHOD(CreateUuid) {
  uuid_t id;
  char uuid_str[37];

  uuid_generate(id);
  my_uuid_unparse_lower(id, uuid_str);

  info.GetReturnValue().Set(New<String>(uuid_str).ToLocalChecked());
}

NAN_MODULE_INIT(init) {
  Set(target, New<String>("create").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(CreateUuid)).ToLocalChecked());
}
NODE_MODULE(uuid, init)
