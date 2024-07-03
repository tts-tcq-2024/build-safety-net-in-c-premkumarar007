#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    c = toupper(c);

    int ans = 0;

    ans = getMatchingSoundexNumericalDigit((c=='B' || c=='F' || c=='P' || c=='V'),ans,1);
    ans = getMatchingSoundexNumericalDigit((c=='C' || c=='G' || c=='J' || c=='K' || c=='Q' || c=='S' || c=='X' || c=='Z'), ans, 2);
    ans = getMatchingSoundexNumericalDigit((c=='D' || c=='T'), ans, 3);
    ans = getMatchingSoundexNumericalDigit((c=='L'), ans, 4);
    ans = getMatchingSoundexNumericalDigit((c=='M' || c=='N'), ans, 5);
    ans = getMatchingSoundexNumericalDigit((c=='R'), ans, 6);

    return ans;
}

int getMatchingSoundexNumericalDigit(int a, int b, int c)
{
    if(a!=0 && b==0) return c;
    return b;
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
