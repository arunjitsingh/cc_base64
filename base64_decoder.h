// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Declares the Base64Decoder class. It uses the Init-Update-Final way of
// decoding blocks/streams of base64 strings.

#ifndef CC_BASE64_BASE64_DECODER_H_
#define CC_BASE64_BASE64_DECODER_H_

#include <string>
#include <sstream>

#include "cc/base64/base64.h"

_START_AJ_NAMESPACE_
namespace base64 {

// Base64 Decoder class for decoding base64 strings.
class Base64Decoder {
 public:
  // Initialize the object with whether the decoder should use websafe
  // characters.
  explicit Base64Decoder();

  // Update the input with some data.
  bool Update(std::string data);

  // Finalize the decoding and return the decoded string.
  std::string Final();

  // Get the size of the decoded block so far.
  size_t size() const {return size_;}
 private:
  byte GetDecodedByte(byte b);
  void Decode(bool finalize = false);

  byte *input_;
  uint inputindex_;
  size_t size_;
  std::stringstream decoded_;
};
}
_END_AJ_NAMESPACE_

#endif  // CC_BASE64_BASE64_DECODER_H_
