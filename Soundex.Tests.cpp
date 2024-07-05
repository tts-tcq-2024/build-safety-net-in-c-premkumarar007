#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
  generateSoundex("Pfister",soundex);
  ASSERT_STREQ(soundex,"P236");
  generateSoundex("Ashcraft",soundex);
  ASSERT_STREQ(soundex,"A261");
}
