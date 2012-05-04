// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Unittest for Base64Decoder. Uses GoogleTest.

#include "cc/base64/base64_decoder.h"
#include "testing/cc/gtest.h"

TEST(Base64DecoderTest, DecodeSingleBlock) {
  std::string input("YXJ1bmppdHNpbmdo");
  ::aj::base64::Base64Decoder dec;
  dec.Update(input);

  std::string expected("arunjitsingh");

  EXPECT_EQ(expected, dec.Final());
}

TEST(Base64DecoderTest, DecodeTwoBlocks) {
  std::string input1("YXJ1bmppd");
  std::string input2("HNpbmdo");
  ::aj::base64::Base64Decoder dec;
  dec.Update(input1);
  dec.Update(input2);

  std::string expected("arunjitsingh");

  EXPECT_EQ(expected, dec.Final());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
