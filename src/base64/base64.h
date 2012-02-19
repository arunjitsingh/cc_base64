// Copyright 2012 Arunjit Singh. All Rights Reserved.
/*
 * Description:
 *     Base64 encoding and decoding header file. Declares the base64 namespace.
 * Author:
 *     Arunjit Singh <arunjit@me.com>
 * Licence:
 *     MIT license. This notice must be included in all distributions.
 *     Copyright: 2012 Arunjit Singh (arunjit@me.com).
 *     See: //LICENSE for details.
 *     See: http://www.opensource.org/licenses/mit-license.php for details.
 */

#ifndef SRC_BASE64_H_
#define SRC_BASE64_H_

#include <string>

#include "aj/base.h"

_START_AJ_NAMESPACE_

namespace base64 {
// Base64 version information.
const unsigned int kVersionMajor = 1;
const unsigned int kVersionMinor = 0;
const unsigned int kVersionPatch = 0;

// The base alphabet used in all Base64 en/de-coding.
const std::string kBaseAlphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz"
                                   "0123456789");

// The default alphabet used for Base64 en/de-coding.
const std::string kDefaultAlphabet = kBaseAlphabet + "+/=";

// A web-safe alphabet for Base64 en/de-coding.
const std::string kWebSafeAlphabet = kBaseAlphabet + "-_.";
}

_END_AJ_NAMESPACE_

#endif  // SRC_BASE64_H_
