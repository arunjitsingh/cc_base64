// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Test for base64 en/de-coding. Not the actual unittest, but something to test
// if I'm on the right track.

#include <base64/base64_encoder.h>
#include <gtest/gtest.h>

TEST(Base64EncoderTest, EncodeSingleBlock) {
  std::string input("arunjitsingh");
  ::aj::base64::Base64Encoder enc;
  enc.Update((void *)input.data(), input.size());
  
  std::string expected("YXJ1bmppdHNpbmdo");

  EXPECT_EQ(expected, enc.Final());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
