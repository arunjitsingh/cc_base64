// Copyright 2012 Arunjit Singh. All Rights Reserved.
// Licence: MIT (http://www.opensource.org/licenses/mit-license.php).
// Redistribution with or without modification must include this notice.
// Author: Arunjit Singh <arunjit@me.com>

// Test for Base64 encoding and decoding. Uses GoogleTest.

#include "cc/base64/base64_encoder.h"
#include "cc/base64/base64_decoder.h"
#include "testing/cc/gtest.h"


TEST(Base64Test, EncodeDecodeString) {
  std::string str("The quick brown fox jumped over the lazy, cross eyed frog");

  ::aj::base64::Base64Encoder enc;
  enc.Update(reinterpret_cast<const void *>(str.data()), str.size());
  std::string encoded = enc.Final();

  ::aj::base64::Base64Decoder dec;
  dec.Update(encoded);

  EXPECT_EQ(str, dec.Final());
}


struct Person {
  std::string name;
  unsigned int age;
};

TEST(Base64Test, EncodeDecodeStruct) {
  Person arunjit;
  arunjit.name = "Arunjit Singh";
  arunjit.age = 21;
  ::aj::base64::Base64Encoder enc;
  enc.Update(reinterpret_cast<const void *>(&arunjit), sizeof(arunjit));
  std::string encoded = enc.Final();

  ::aj::base64::Base64Decoder dec;
  dec.Update(encoded);
  const Person *decoded = reinterpret_cast<const Person *>(dec.Final().data());

  EXPECT_EQ(decoded->name, arunjit.name);
  EXPECT_EQ(decoded->age, arunjit.age);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
