#include <stdio.h>
#include <limits.h>
#include <math.h>

void p2_1()
{
  printf("signed char min = %d\n", SCHAR_MIN);
  printf("signed char min = %d\n", -(char)((unsigned char)~0 >> 1));
  printf("unsigned long max = %lu\n", ULONG_MAX);
  printf("unsigned long max = %lu\n", (unsigned long)~0);
}

/* convert hexdecimal string s to integer */
int p2_3_htoi(char s[])
{
#define YES 1
#define NO 0
  int hexdigit, i, inhex, n;
  i = 0;
  if (s[i] == '0')
  {
    i += 1;
    if (s[i] == 'x' || s[i] == 'X')
    {
      i += 1;
    }
  }
  n = 0;
  inhex = YES;
  for (; inhex == YES; ++i)
  {
    if (s[i] > '0' && s[i] <= '9')
    {
      hexdigit = s[i] - '0';
    }
    else if (s[i] >= 'a' && s[i] <= 'f')
    {
      hexdigit = s[i] - 'a' + 10;
    }
    else if (s[i] >= 'A' && s[i] <= 'F')
    {
      hexdigit = s[i] - 'A' + 10;
    }
    else
    {
      inhex = NO;
    }
    if (inhex == YES)
    {
      n = 16 * n + hexdigit;
    }
  }
  return n;
}

void p2_4_squeeze(char s1[], char s2[])
{
  int i, j, k;
  for (i = k = 0; s1[i] != '\0'; i++)
  {
    for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
    {
      ;
    }
    if (s2[j] == '\0')
    {
      s1[k++] = s1[i];
    }
  }
  s1[k] = '\0';
  printf("s1 = %s\n", s1);
  printf("s2 = %s\n", s2);
}

int p2_5_any(char s1[], char s2[])
{
  for (int i = 0; s1[i] != '\0'; i++)
  {
    for (int j = 0; s2[j] != '\0'; j++)
    {
      if (s1[i] == s2[j])
      {
        return i;
      }
    }
  }
  return -1;
}

int p2_10_lower(int c)
{
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

int main(int argc, char const *argv[])
{
  // p2_1_1();

  // printf("num = %d\n", p2_3_htoi("0x1f"));

  // p2_4_squeeze("asdfg", "asefh");

  // printf("index = %d\n", p2_5_any("acv", "rab"));

  // printf("lower = %d\n", p2_10_lower('A'));

  char s2[] = "I am a string";
  *(s2 + 1) = 'S';

  printf("%s", s2);

  return 0;
}
