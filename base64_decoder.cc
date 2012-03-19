// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Implementation of the Base64Decoder class.

#include "cc/base64/base64_decoder.h"

_START_AJ_NAMESPACE_
namespace base64 {

Base64Decoder::Base64Decoder() {
  size_ = 0;
  inputindex_ = 0;
  input_ = new byte[kBufferSize];
}

byte Base64Decoder::GetDecodedByte(byte b) {
  if (b >= 'A' && b <= 'Z') {
    return b - 'A';
  } else if (b >= 'a' && b <= 'z') {
    return 26 + b - 'a';
  } else if (b >= '0' && b <= '9') {
    return 52 + b - '0';
  } else {
    switch (b) {
      case '-':  // fallthru
      case '+': return 62;
      case '_':  // fallthru
      case '/': return 63;
      case '.':  // fallthru
      case '=': return 64;
      default: return 255;
    }
  }
}

void Base64Decoder::Decode(bool finalize) {
  if (finalize && inputindex_ % 4 != 0) {
    // Don't have enough bytes to finalize
    return;
  }
  byte c1, c2, c3, c4, e1, e2, e3;
  uint i = 0;
  while (i < inputindex_ - (inputindex_ % 4)) {
    c1 = GetDecodedByte(input_[i++]);
    c2 = GetDecodedByte(input_[i++]);
    c3 = GetDecodedByte(input_[i++]);
    c4 = GetDecodedByte(input_[i++]);

    if (c1 > 64 || c2 > 64 || c3 > 64 || c4 > 64) {
      break;
    }

    e1 = (c1 << 2) | (c2 >> 4);
    decoded_ << e1;
    if (c3 < 64) {
      e2 = ((c2 & 15) << 4) | (c3 >> 2);
      decoded_ << e2;
      if (c4 < 64) {
        e3 = ((c3 & 3) << 6) | c4;
        decoded_ << e3;
      }
    }
  }
  inputindex_ = inputindex_ % 4;
}

bool Base64Decoder::Update(std::string data) {
  size_t size = data.size();
  uint i;
  // Put bytes in input_, but only till their count is a multiple of 4.
  for (i = 0; i < size; ++i) {
    input_[inputindex_++] = data[i];
    if (inputindex_ == kBufferSize) {
      Decode();
    }
  }
  // Decode input_ only if input_ has enough bytes.
  if (inputindex_ && inputindex_ % 4 == 0) {
    Decode();
  }
  return true;
}

std::string Base64Decoder::Final() {
  // Encode it one last time for all the remaining bytes.
  Decode(true);
  return decoded_.str();
}

}
_END_AJ_NAMESPACE_