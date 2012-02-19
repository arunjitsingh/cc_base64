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

TEST(Base64EncoderTest, EncodeTwoBlocks) {
  std::string input1("arunjit");
  std::string input2("singh");
  ::aj::base64::Base64Encoder enc;
  enc.Update((void *)input1.data(), input1.size());
  enc.Update((void *)input2.data(), input2.size());

  std::string expected("YXJ1bmppdHNpbmdo");

  EXPECT_EQ(expected, enc.Final());
}

TEST(Base64EncoderTest, EncodeMultipleBlocks) {
  //"The quick brown fox jumped over the lazy dog"
  std::string input1("The ");
  std::string input2("quick ");
  std::string input3("brown ");
  std::string input4("fox ");
  std::string input5("jumped ");
  std::string input6("over ");
  std::string input7("the ");
  std::string input8("lazy ");
  std::string input9("dog");
  ::aj::base64::Base64Encoder enc;
  enc.Update((void *)input1.data(), input1.size());
  enc.Update((void *)input2.data(), input2.size());
  enc.Update((void *)input3.data(), input3.size());
  enc.Update((void *)input4.data(), input4.size());
  enc.Update((void *)input5.data(), input5.size());
  enc.Update((void *)input6.data(), input6.size());
  enc.Update((void *)input7.data(), input7.size());
  enc.Update((void *)input8.data(), input8.size());
  enc.Update((void *)input9.data(), input9.size());

  std::string expected("VGhlIHF1aWNrIGJyb3duIGZveCBqdW"
                       "1wZWQgb3ZlciB0aGUgbGF6eSBkb2c=");

  EXPECT_EQ(expected, enc.Final());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
