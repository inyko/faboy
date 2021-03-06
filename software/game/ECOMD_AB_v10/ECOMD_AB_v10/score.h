#ifndef SCORE_H
#define SCORE_H


//define score font size
#define SCORE_SMALL_FONT          0
#define SCORE_BIG_FONT            1

PROGMEM const unsigned char numbersSmall[] = {
// width, height
3, 8,
// frame 0
0x1F, 0x11, 0x1F, 
// frame 1
0x12, 0x1F, 0x10, 
// frame 2
0x1D, 0x15, 0x17, 
// frame 3
0x11, 0x15, 0x1F, 
// frame 4
0x07, 0x04, 0x1F, 
// frame 5
0x17, 0x15, 0x1D, 
// frame 6
0x1F, 0x15, 0x1D, 
// frame 7
0x01, 0x01, 0x1F, 
// frame 8
0x1F, 0x15, 0x1F, 
// frame 9
0x17, 0x15, 0x1F, 
};


PROGMEM const unsigned char numbersBig[] = {
// width, height
18, 32,
// frame 0
0x40, 0xE0, 0x98, 0xFC, 0xFC, 0xF4, 0x1C, 0x1C, 0x14, 0x14, 
0x7C, 0xF4, 0xFE, 0xF5, 0xD8, 0x08, 0x00, 0x00, 0x00, 0xF8, 
0xBF, 0xFF, 0xFF, 0xEF, 0x00, 0x00, 0x00, 0x02, 0x71, 0xEB, 
0xFF, 0xFF, 0xFE, 0x8E, 0x80, 0x00, 0x02, 0x19, 0xFE, 0xFF, 
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x6F, 0xDF, 0xFF, 0xFF, 
0xFF, 0x00, 0x00, 0x00, 0x00, 0x28, 0x7F, 0x5F, 0x7F, 0x1F, 
0x78, 0x68, 0x70, 0x71, 0x61, 0xF5, 0xBF, 0x7F, 0x27, 0x18, 
0x00, 0x00, 
// frame 1
0x00, 0x00, 0x00, 0x00, 0x10, 0x1C, 0xFE, 0xFE, 0xFE, 0xEE, 
0x78, 0xE0, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x40, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x00, 
0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x20, 0xFF, 0xFF, 0xFF, 0xFB, 0xF3, 0x0C, 0x88, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x83, 
0x3F, 0x7F, 0x7F, 0x7F, 0x3F, 0x25, 0x06, 0x44, 0x00, 0x00, 
0x00, 0x00, 
// frame 2
0x00, 0xF8, 0xF4, 0xFC, 0xFE, 0xFF, 0x1E, 0x1C, 0x1F, 0x1B, 
0xF8, 0xF8, 0xFE, 0xFC, 0x98, 0x00, 0x00, 0x20, 0x00, 0x01, 
0x0B, 0x03, 0x03, 0x09, 0x05, 0x80, 0xC0, 0xE9, 0xEA, 0xFF, 
0xFF, 0xFF, 0x3F, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
0xC0, 0xF8, 0xFD, 0xFB, 0x7F, 0x3F, 0x1F, 0x37, 0x13, 0x03, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x78, 0x9E, 0x7D, 0x7F, 0xFF, 
0x7D, 0x7B, 0x39, 0x78, 0x78, 0x78, 0xF8, 0xB8, 0x38, 0x00, 
0x00, 0x00, 
// frame 3
0x00, 0x78, 0xF8, 0x7C, 0x7C, 0xFE, 0x1A, 0x30, 0x2E, 0x0B, 
0x1D, 0xFB, 0xFC, 0xE4, 0xF8, 0x40, 0x00, 0x00, 0x00, 0x00, 
0x01, 0x03, 0x03, 0xE3, 0xC0, 0xE0, 0xE0, 0xE4, 0xF9, 0xFF, 
0xFF, 0xBF, 0xBF, 0x00, 0x00, 0x00, 0x10, 0x28, 0x70, 0xF0, 
0xF4, 0xF9, 0x00, 0x03, 0x03, 0x01, 0x2B, 0xF7, 0xFF, 0xFF, 
0xFF, 0x60, 0x00, 0x00, 0x00, 0x18, 0x07, 0x3F, 0x3F, 0x3F, 
0x7C, 0x18, 0x30, 0x28, 0x3C, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 
0x00, 0x00, 
// frame 4
0x00, 0x00, 0x80, 0x80, 0x00, 0xC2, 0xFC, 0xF0, 0xFE, 0xFE, 
0x3C, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
0x88, 0x78, 0xEC, 0xE3, 0xFF, 0x6F, 0x0D, 0x03, 0x20, 0xE0, 
0xE0, 0xE0, 0xA0, 0x00, 0x00, 0x00, 0xE4, 0xFC, 0xFF, 0xFF, 
0xFF, 0xCD, 0xE2, 0xF0, 0xF0, 0xA0, 0xFE, 0xFB, 0xFF, 0xFF, 
0xFC, 0xC0, 0x38, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x7F, 0x7F, 0x1F, 0x3F, 0xDC, 0x09, 
0x00, 0x00, 
// frame 5
0x00, 0x00, 0x20, 0xF6, 0xFE, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 
0x1C, 0x1C, 0xBC, 0x2C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x65, 0x7F, 0xFF, 0xFF, 0x7F, 0x70, 0x60, 0xF0, 0xF0, 0xF0, 
0xF0, 0x70, 0xB0, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 
0xE0, 0xE0, 0xE0, 0x03, 0x03, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 
0xFE, 0xFF, 0x02, 0x00, 0x00, 0x00, 0x05, 0x3E, 0x3F, 0x7F, 
0x3F, 0x78, 0x58, 0x58, 0x78, 0x7B, 0x7F, 0x3F, 0x7F, 0xBD, 
0x10, 0x00, 
// frame 6
0x00, 0x00, 0x80, 0xFC, 0xFC, 0xFA, 0xFC, 0x1C, 0x0E, 0x0C, 
0x16, 0x1A, 0x1E, 0x1E, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x30, 0xDF, 0xFF, 0xFF, 0xFF, 0x72, 0x79, 0x78, 0x78, 0xF8, 
0xF8, 0xF8, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x88, 0xEE, 0xFF, 
0xFF, 0xCD, 0xCF, 0x00, 0x02, 0x00, 0x41, 0xBF, 0x7F, 0xFF, 
0xFF, 0xFB, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x7F, 0x9F, 0x3F, 
0x9F, 0xBC, 0x8C, 0x58, 0x38, 0x3F, 0x7F, 0x5F, 0x3F, 0x2F, 
0x00, 0x00, 
// frame 7
0x00, 0x00, 0x00, 0x3E, 0x1E, 0x3E, 0x5C, 0x3D, 0x3C, 0x3C, 
0xFC, 0xFC, 0xFC, 0xFC, 0x7C, 0x3C, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xB0, 0xFF, 0x7F, 0xFF, 
0xCF, 0x15, 0x23, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x50, 0xD0, 0xFD, 0xFD, 0xFD, 0xFF, 0x1F, 0x03, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x49, 0x3F, 0xFF, 
0xFF, 0x7F, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 
// frame 8
0x00, 0xA4, 0xFE, 0xF2, 0xFE, 0xFE, 0x3C, 0x3C, 0x3C, 0x1C, 
0x34, 0xFC, 0xFC, 0xD4, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x37, 0xBF, 0xFF, 0xDF, 0x64, 0x40, 0xC0, 0xF0, 0xC0, 0xFF, 
0xFF, 0xFF, 0xBF, 0xA0, 0x9B, 0x00, 0x00, 0xD1, 0xEC, 0xFE, 
0xFF, 0xFF, 0xBF, 0x41, 0x11, 0x11, 0x29, 0x7F, 0xFF, 0xBF, 
0xFF, 0x0E, 0x00, 0x00, 0x00, 0x04, 0x1B, 0x7F, 0xBF, 0x3F, 
0xB3, 0x72, 0xA1, 0xA2, 0xF3, 0xFF, 0x7F, 0x7F, 0x3F, 0x5F, 
0x20, 0x00, 
// frame 9
0x60, 0x00, 0xB7, 0xFD, 0xF2, 0xFE, 0x7E, 0xA6, 0x1E, 0x0A, 
0x1E, 0xFE, 0xFE, 0xFC, 0x58, 0xC0, 0x80, 0x00, 0x20, 0x80, 
0xFD, 0xF7, 0xCF, 0xF9, 0x35, 0x08, 0x00, 0x28, 0xB5, 0xFC, 
0xFF, 0xE7, 0xBF, 0x10, 0x09, 0x07, 0x00, 0x31, 0x17, 0x1F, 
0x2B, 0x1D, 0x17, 0x0E, 0x16, 0xAA, 0x7D, 0xFF, 0xFF, 0xFF, 
0xFF, 0x08, 0x00, 0x00, 0x00, 0x00, 0x38, 0x78, 0x78, 0x78, 
0x6C, 0x78, 0x78, 0x7B, 0x3C, 0x7F, 0x5F, 0x5F, 0x2E, 0x28, 
0x00, 0x00, 
};

void drawScore(byte scoreX, byte scoreY, byte fontType)
{
  char buf[10];
  //scorePlayer = arduboy.cpuLoad();
  itoa(scorePlayer, buf, 10);
  char charLen = strlen(buf);
  char pad = 5 - charLen;

  //draw 0 padding
  for (byte i = 0; i < pad; i++)
  {
    switch (fontType)
    {
      case SCORE_SMALL_FONT:
        sprites.drawSelfMasked(scoreX + (4 * i), scoreY, numbersSmall, 0);
        break;
      case SCORE_BIG_FONT:
        sprites.drawSelfMasked(scoreX + (20 * i), scoreY, numbersBig, 0);
        break;
    }
  }

  for (byte i = 0; i < charLen; i++)
  {
    char digit = buf[i];
    byte j;
    if (digit <= 48)
    {
      digit = 0;
    }
    else {
      digit -= 48;
      if (digit > 9) digit = 0;
    }

    for (byte z = 0; z < 10; z++)
    {
      if (digit == z) j = z;
    }
    switch (fontType)
    {
      case SCORE_SMALL_FONT:
        sprites.drawSelfMasked(scoreX + (pad * 4) + (4 * i), scoreY, numbersSmall, digit);
        break;
      case SCORE_BIG_FONT:
        sprites.drawSelfMasked(scoreX + (pad * 20) + (20 * i), scoreY, numbersBig, digit);
        break;
    }
  }
}

#endif
