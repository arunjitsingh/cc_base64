// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Common header for Base64 encoding and decoding. Provides the base64 namespace
// and initializes the base64 alphabet for 2 forms: default and websafe.

#ifndef CC_BASE64_BASE64_H_
#define CC_BASE64_BASE64_H_

#include <string>

#include "cc/base.h"

_START_AJ_NAMESPACE_

namespace base64 {
// Some more types, for ease of use.
typedef unsigned char byte;
typedef unsigned int uint;

// Base64 version information.
const uint kVersionMajor = 1;
const uint kVersionMinor = 0;
const uint kVersionPatch = 0;

// The base alphabet used in all Base64 en/de-coding.
const std::string kBaseAlphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz"
                                   "0123456789");

// The default alphabet used for Base64 en/de-coding.
const std::string kDefaultAlphabet = kBaseAlphabet + "+/=";

// A web-safe alphabet for Base64 en/de-coding.
const std::string kWebSafeAlphabet = kBaseAlphabet + "-_.";

const size_t kBufferSize = 384;
}

_END_AJ_NAMESPACE_

#endif  // CC_BASE64_BASE64_H_
