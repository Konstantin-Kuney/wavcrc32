/*
----------------------------------------------------------
wavcrc32.cpp
Version 0.22
----------------------------------------------------------
A program for counting audiodata CRC checksums
that used in EAC (Exact Audio Copy by Andre Wiethoff)
----------------------------------------------------------
This program is freeware and open-source, you may
freely redistribute or modify it, or use code in your
applications.
----------------------------------------------------------
I hope this code can be compiled with any C/C++ compiler
like microsoft visual c++, gcc, open-watcom c/c++, ...
If you experience any problems with compiling this program
you may feel free to ask me, what's the hell it is, maybe
I can help you.
At this time I've checked that
* gcc/g++ 3.4.4 @ cygwin
* msvc 8.0
* open watcom c/c++ 1.6
work fine with this code!
----------------------------------------------------------
(c) ]DichlofoS[ Systems, 2007
mailto:dmvn@mccme.ru
----------------------------------------------------------
*/
#if _MSC_VER >= 1400
  // this option is for Safe STDLIB fopen_s, etc functions
  #define MSC_SAFECODE 1
#else
  #undef MSC_SAFECODE
#endif
#include <stdio.h>
#include <stdlib.h>
#if _MSC_VER >= 1400
  #include <windows.h>
#endif
#define SAMPLE_BUFFER_SIZE 1024
// Function prototypes
void InitCRC32Table();
unsigned int Reflect(unsigned int ref, char ch);
bool CheckDWORD(FILE* f, unsigned int nOffset, unsigned int nProperValue, const char* szMessage);
unsigned int CheckRIFFHeader(FILE* f);
unsigned int CRC32Table[256];
// Call this function only once to initialize the CRC table
void InitCRC32Table()
{
  unsigned int ulPolynomial = 0x04c11db7;
  // 256 values representing ASCII character codes.
  for(int i = 0; i <= 0xFF; i++)
  {
    CRC32Table[i] = Reflect(i, 8) << 24;
    for (int j = 0; j < 8; j++)
      CRC32Table[i] = (CRC32Table[i] << 1) ^ (CRC32Table[i] & (1 << 31) ? ulPolynomial : 0);
    CRC32Table[i] = Reflect(CRC32Table[i], 32);
  }
}
/*
  Reflection is a requirement for the official CRC-32 standard.
  You can create CRCs without it, but they won't conform to the standard.
  Used only by InitCRC32Table()
*/
unsigned int Reflect(unsigned int ref, char ch)
{
  unsigned int value(0);
  // Swap bit 0 for bit 7
  // bit 1 for bit 6, etc.
  for (int i = 1; i < (ch + 1); i++)
  {
    if (ref & 1)
      value |= 1 << (ch - i);
    ref >>= 1;
  }
  return value;
}
/*
  Checks DWORD in WAV file on validness
*/
bool CheckDWORD(FILE* f, unsigned int nOffset, unsigned int nProperValue, const char* szMessage)
{
  unsigned int dwCheck = 0;
  fseek(f, nOffset, SEEK_SET);
  fread(&dwCheck, 1, 4, f);
  if (dwCheck != nProperValue)
  {
    printf("%s\n", szMessage);
    return false;
  }
  return true;
}
/*
  Checks RIFF header in WAV file on validness
*/
unsigned int CheckRIFFHeader(FILE* f)
{
  if (!CheckDWORD(f, 0x00, 0x46464952, "*** non-RIFF format!")) return 0;
  if (!CheckDWORD(f, 0x08, 0x45564157, "*** non-WAVE format!")) return 0;
  if (!CheckDWORD(f, 0x0C, 0x20746d66, "*** cannot find format chunk!")) return 0;
  if (!CheckDWORD(f, 0x10, 0x00000010, "*** invalid format chunk size!")) return 0;
  if (!CheckDWORD(f, 0x14, 0x00020001, "*** invalid audio format!")) return 0;
  if (!CheckDWORD(f, 0x24, 0x61746164, "*** cannot find data chunk!")) return 0;
  unsigned int dwDataSize = 0;
  fseek(f, 0x28, SEEK_SET);
  fread(&dwDataSize, 1, 4, f);
  return dwDataSize;
}
int main(int argc, char** argv)
{
  InitCRC32Table();
#if _MSC_VER >= 1400
  DWORD StartTime = GetTickCount();
#endif
  printf("EAC wavcrc32 v0.22 (c) ]DichlofoS[ Systems, 2007\nthanx to: BakLAN, siro and other beta-testers/contributors!\n");
  if (argc != 2)
  {
    printf("*** invalid cmdline arguments!\nsyntax: wavcrc32 filename.wav\n");
    return -1;
  }
  const char* sFileName = argv[1];
#ifdef MSC_SAFECODE
  FILE* f = 0;
  fopen_s(&f, sFileName, "rb");
#else
  FILE* f = fopen(sFileName, "rb");
#endif
  if (!f)
  {
    printf("*** cannot open file!\n");
    return -1;
  }
  printf("file opened ok\n");
  // check header
  unsigned int nDataSize = CheckRIFFHeader(f);
  if (!nDataSize)
  {
    fclose(f);
    return -1;
  }
  printf("RIFF header checked ok\n");
  unsigned char chBuffer[4*SAMPLE_BUFFER_SIZE];
  unsigned int nSampleCount = nDataSize >> 2;
  unsigned int crc(0xffffffff);
  unsigned int crcns(0xffffffff);
  unsigned int crcnsl(0xffffffff);
  unsigned int crcnslr(0xffffffff);
  unsigned int crcnb(0xffffffff);
  printf("please wait while couning checksums...\n");
  printf("processing %d samples...\n", nSampleCount);
  unsigned int i = 0;
  while (i < nSampleCount)
  {
    unsigned int nCurrentBlockSize = nSampleCount - i;
    if (nCurrentBlockSize > SAMPLE_BUFFER_SIZE) nCurrentBlockSize = SAMPLE_BUFFER_SIZE;
    if (fread(chBuffer, 1, 4*nCurrentBlockSize, f) != 4*nCurrentBlockSize)
    {
      printf("*** cannot read from input file!\n");
      fclose(f);
      printf("file closed ok\n");
      return -1;
    }
    i += nCurrentBlockSize;
    for (unsigned int k = 0; k < nCurrentBlockSize; k++)
    {
      unsigned char nSample[4];
      *(unsigned int*)nSample = *((unsigned int*)chBuffer+k);
      // calculate checksum skipping nulsamples
      if (*(unsigned int*)nSample)
        for (int j = 0; j < 4; j++)
          crcns = (crcns >> 8) ^ CRC32Table[(crcns & 0xFF) ^ nSample[j]];
      // calculate checksum skipping nulsamples on left/right channel
      if (nSample[0] || nSample[1])
        for (int j = 0; j < 2; j++)
          crcnslr = (crcnslr >> 8) ^ CRC32Table[(crcnslr & 0xFF) ^ nSample[j]];
      if (nSample[2] || nSample[3])
        for (int j = 2; j < 4; j++)
          crcnslr = (crcnslr >> 8) ^ CRC32Table[(crcnslr & 0xFF) ^ nSample[j]];
      // calculate non-zero-bytes checksum on left channel
      if (nSample[0] || nSample[1])
        for (int j = 0; j < 2; j++)
          crcnsl = (crcnsl >> 8) ^ CRC32Table[(crcnsl & 0xFF) ^ nSample[j]];
      // calculate non-zero-bytes checksum
      for (int j = 0; j < 4; j++)
        if (nSample[j])
          crcnb = (crcnb >> 8) ^ CRC32Table[(crcnb & 0xFF) ^ nSample[j]];
      // calculate standard checksum
      for (int j = 0; j < 4; j++)
        crc = (crc >> 8) ^ CRC32Table[(crc & 0xFF) ^ nSample[j]];
    }
  }
  fclose(f);
  printf("file closed ok\n");
  crc = crc^0xffffffff;
  crcns = crcns^0xffffffff;
  crcnsl = crcnsl^0xffffffff;
  crcnslr = crcnslr^0xffffffff;
  crcnb = crcnslr^0xffffffff;
  printf("--- used in EAC:\n");
  printf("generic: grabbing, \"no use...\" off [all bytes]            : %08X.\n", crc);
  printf("generic: grabbing, \"no use...\" on [word nulsamples l/r]   : %08X.\n", crcnslr);
  printf("waveditor [word nulsamples l]                             : %08X.\n", crcnsl);
  printf("--- no used in EAC, only for reference:\n");
  printf("byte ignore zeros                                         : %08X.\n", crcnb);
  printf("dword nulsamples                                          : %08X.\n", crcns);
#if _MSC_VER >= 1400
  printf("---\ntime elapsed: %d ms\n", GetTickCount()-StartTime);
#endif
  return 0;
}
