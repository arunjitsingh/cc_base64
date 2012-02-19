// Copyright 2012 Arunjit Singh. All Rights Reserved.
/*
 * Description:
 *     Base64 encoding. Implementation of the Base64Encoder class.
 * Author:
 *     Arunjit Singh <arunjit@me.com>
 * Licence:
 *     MIT license. This notice must be included in all distributions.
 *     Copyright: 2012 Arunjit Singh (arunjit@me.com).
 *     See: //LICENSE for details.
 *     See: http://www.opensource.org/licenses/mit-license.php for details.
 */

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