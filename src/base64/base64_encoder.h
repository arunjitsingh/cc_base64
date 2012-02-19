// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Declares the Base64Encoder class. It uses the Init-Update-Final way of
// encoding blocks/streams of data.

#ifndef SRC_BASE64_ENCODER_H_
#define SRC_BASE64_ENCODER_H_

#include <string>

#include <base64/base64.h>

_START_AJ_NAMESPACE_
namespace base64 {

// Base64 Encoder class for encoding data into base64.
class Base64Encoder {
 public:
  explicit Base64Encoder(bool use_websafe = false);
  bool Update(void *data, size_t size);
  std::string Final();
 private:
  bool iswebsafe_;
  std::string input_;
  std::string encoded_;
  size_t size_;
};
}
_END_AJ_NAMESPACE_

#endif  // SRC_BASE64_ENCODER_H_
