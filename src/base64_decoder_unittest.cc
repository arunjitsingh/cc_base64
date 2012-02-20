// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Unittest for Base64Decoder. Uses GoogleTest.

#include <base64/base64_decoder.h>
#include <gtest/gtest.h>

TEST(Base64EncoderTest, EncodeSingleBlock) {
  std::string input("YXJ1bmppdHNpbmdo");
  ::aj::base64::Base64Decoder dec;
  dec.Update(input);

  std::string expected("arunjitsingh");

  EXPECT_EQ(expected, dec.Final());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
