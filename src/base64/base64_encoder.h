// Copyright 2012 Arunjit Singh. All Rights Reserved.
/*
 * Description:
 *     Base64 encoding. Declares the Base64Encoder class.
 * Author:
 *     Arunjit Singh <arunjit@me.com>
 * Licence:
 *     MIT license. This notice must be included in all distributions.
 *     Copyright: 2012 Arunjit Singh (arunjit@me.com).
 *     See: //LICENSE for details.
 *     See: http://www.opensource.org/licenses/mit-license.php for details.
 */

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
  bool Update(void *data, unsigned int size);
  std::string Final();
 private:
  bool iswebsafe_;
  std::string input_;
  std::string encoded_;
};
}
_END_AJ_NAMESPACE_

#endif  // SRC_BASE64_ENCODER_H_
