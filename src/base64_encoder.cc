// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Implementation of the Base64Encoder class.

#include "base64/base64_encoder.h"

_START_AJ_NAMESPACE_
namespace base64 {

Base64Encoder::Base64Encoder(bool use_websafe) {
  iswebsafe_ = use_websafe;
}

bool Update(void *data, size_t size) {
  return false;
}

std::string Final() {
  return std::string("");
}

}
_END_AJ_NAMESPACE_