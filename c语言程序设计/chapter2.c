#include <stdio.h>
#include <limits.h>
#include <math.h>

void p2_1() 
{
  printf("signed char min = %d\n", SCHAR_MIN);
  printf("signed char min = %d\n", -(char)((unsigned char) ~ 0 >> 1));
  printf("unsigned long max = %lu\n", ULONG_MAX);
  printf("unsigned long max = %lu\n", (unsigned long) ~ 0);
}

/* convert hexdecimal string s to integer */
int p2_3_htoi(char s[])
{
  #define YES 1
  #define NO 0
  int hexdigit, i, inhex, n;
  i = 0;
  if(s[i] == '0') {
    i += 1;
    if(s[i] == 'x' || s[i] == 'X') {
      i += 1;
    }
  }
  n = 0;
  inhex = YES;
  for(; inhex == YES; ++i) {
    if(s[i] > '0' && s[i] <= '9') {
      hexdigit = s[i] - '0';
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      hexdigit = s[i] - 'a' + 10;
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      hexdigit = s[i] - 'A' + 10;
    } else {
      inhex = NO;
    }
    if (inhex == YES) {
      n = 16 * n + hexdigit;
    }
  }
  return n;
}



int main(int argc, char const *argv[])
{
  // p2_1_1();

  // int num = p2_3_htoi("0x1f");
  // printf("num = %d\n", num);

  return 0;
}
