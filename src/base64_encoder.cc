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
  size_ = 0;
  inputindex_ = 0;
  input_ = new byte[kBufferSize];
}

void Base64Encoder::Encode(bool finalize) {
  if (!finalize && inputindex_ % 3 != 0) {
    // Unless finalized, don't have enough bytes yet to encode.
    return;
  }
  byte c1, c2, c3, e1, e2, e3, e4;
  bool h2, h3;
  uint i = 0;
  while (i < inputindex_) {
    c1 = input_[i++];
    h2 = i < inputindex_;
    c2 = h2 ? input_[i++] : 0;
    h3 = i < inputindex_;
    c3 = h3 ? input_[i++] : 0;

    e1 = c1 >> 2;
    e2 = ((c1 & 3) << 4) | (c2 >> 4);
    e3 = ((c2 & 15) << 2) | (c3 >> 6);
    e4 = c3 & 63;

    if (!h2) {
      e4 = e3 = 64;
    } else if (!h3) {
      e4 = 64;
    }
    if (iswebsafe_) {
      encoded_ << kWebSafeAlphabet[e1] << kWebSafeAlphabet[e2]
               << kWebSafeAlphabet[e3] << kWebSafeAlphabet[e4];
    } else {
      encoded_ << kDefaultAlphabet[e1] << kDefaultAlphabet[e2]
               << kDefaultAlphabet[e3] << kDefaultAlphabet[e4];
    }
  }
  inputindex_ = 0;
}

bool Base64Encoder::Update(void *data, size_t size) {
  byte *bytes = reinterpret_cast<byte *>(data);
  uint i;
  // Put bytes in input_, but only till their count is a multiple of 3.
  for (i = 0; i < size - (size % 3); ++i) {
    input_[inputindex_++] = bytes[i];
    if (inputindex_ == kBufferSize) {
      Encode();
    }
  }
  // Encode input_ only if inputindex_ hasn't been reset.
  if (inputindex_) {
    Encode();
  }
  // Put remaining bytes in input_. There can only be either 1 or 2 bytes left.
  for (; i < size; ++i) {
    input_[inputindex_++] = bytes[i];
  }
  return true;
}

std::string Base64Encoder::Final() {
  // Encode it one last time for all the remaining bytes.
  Encode(true);
  return encoded_.str();
}

}
_END_AJ_NAMESPACE_