// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Test for base64 en/de-coding. Not the actual unittest, but something to test
// if I'm on the right track.

#include <iostream>

#include <base64/base64_encoder.h>

int main() {
  std::string input("arunjitsingh");
  ::aj::base64::Base64Encoder enc;
  enc.Update((void *)input.c_str(), input.size());
  std::cout << enc.Final() << std::endl;
  return 0;
}
