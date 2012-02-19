#include "base64/base64_encoder.h"

_START_AJ_NAMESPACE_
namespace base64 {

Base64Encoder::Base64Encoder(bool use_websafe) {
  iswebsafe_ = use_websafe;
}

bool Update(void *data, unsigned int size) {
  return false;
}

std::string Final() {
  return std::string("");
}

}
_END_AJ_NAMESPACE_