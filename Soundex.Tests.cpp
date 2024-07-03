#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  generateSoundex("Robert", soundex);
  generateSoundex("Rupert", soundex);
  generateSoundex("Pfister", soundex);
  generateSoundex("Prem890", soundex);
 // ASSERT_EQ(soundex,"A200");
}
