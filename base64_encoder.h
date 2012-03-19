// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Declares the Base64Encoder class. It uses the Init-Update-Final way of
// encoding blocks/streams of data.

#ifndef CC_BASE64_BASE64_ENCODER_H_
#define CC_BASE64_BASE64_ENCODER_H_

#include <string>
#include <sstream>

#include "cc/base64/base64.h"

_START_AJ_NAMESPACE_
namespace base64 {

// Base64 Encoder class for encoding data into base64.
class Base64Encoder {
 public:
  // Initialize the object with whether the encoder should use websafe
  // characters.
  explicit Base64Encoder(bool use_websafe = false);

  // Update the input with some data.
  bool Update(const void *data, size_t size);

  // Finalize the encoding and return the encoded base64 string.
  std::string Final();

  // Get the size of the encoded block so far.
  size_t size() const {return size_;}
 private:
  void Encode(bool finalize=false);

  bool iswebsafe_;
  byte *input_;
  uint inputindex_;
  size_t size_;
  std::stringstream encoded_;
};
}
_END_AJ_NAMESPACE_

#endif  // CC_BASE64_BASE64_ENCODER_H_
