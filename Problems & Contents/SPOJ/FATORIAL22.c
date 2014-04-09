#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bigNumber[200];
/*a[0] is the number of digits
  a[1] is the least significant digit,...,
  a[a[0]] is the most significant digit */

int power2[4]={6, 2, 4, 8};
int power3[4]={1, 3, 9, 7};
int power7[4]={1, 7, 9, 3};
int power9[4]={1, 9, 1, 9};

int isZero(bigNumber a) {
  if (a[0] ==0) return 1;
  return 0;
}

int mod4(bigNumber a)
{
  int i;

  if(a[0] ==0) return 0;
  i =a[1];
  if(a[0]>1) i =i+10*a[2];
  return i%4;
}

void stringToNumber(char *s, bigNumber b) {
  int i;

  while(*s == '0') s++;  //skip leading zeroes
  b[0] = strlen(s);
  for(i = 0; i < strlen(s);  i++) {
    b[strlen(s)-i] = s[i]-'0';
  }
}

int divide(bigNumber a, int b) {
/* divides big number a by integer b and returns remainder */
  int i, r =0;
  for(i = a[0]; i>=1; i--) {
    r = r*10 + a[i];
    a[i] = r / b;
    r = r % b;
  }
  i = a[0];
  while ((i > 0) && (a[i] == 0)) i--;
  a[0] = i;
  return r;
}

void copyNumber(bigNumber b, bigNumber a) {
  int i;
  for(i = 0; i <= a[0]; i++) b[i] = a[i];
}

int computePowerOf2(bigNumber a) {
/*computes the last digit of power of two involved in resul */
  int power = 0;
  bigNumber p1;

  if(a[0] == 1 && a[1] == 1) return 1;

  copyNumber(p1, a);
  while (!isZero(p1)) {
    divide(p1, 2);
    power = (power + mod4(p1)) % 4;
  }

  copyNumber(p1, a);
  while (!isZero(p1)) {
    divide(p1, 5);
    power =(power - mod4(p1) + 4)%4;
  }
  return power2[power];
}

int compute379(bigNumber p) {
  /* computes the last digit of product of
     all numbers smaller then p and ending in 3, 7 a 9 */
  bigNumber p1;
  int r, poc, result;

  copyNumber(p1, p);
  r = divide(p1, 10);
  poc = mod4(p1);

  result = (power3[poc] * power7[poc] * power9[poc]) % 10;
  if (r >= 3) result *= 3;
  if (r >= 7) result *= 7;
  if (r >= 9) result *= 9;

  return result % 10;
}

int factorial(bigNumber p) {
/* computes the last digit od p! */

  bigNumber pp, ppp;
  int result;


  /* first compute power of 2 */
  result = computePowerOf2(p);

  /* now compute powers of 3, 7 and 9 */
  copyNumber(pp, p);
  while(! isZero(pp)) {
    /* divide p by all cobinations of 2^i, 5^j */
    copyNumber(ppp, pp);

    while(! isZero(ppp)) {
      result *= compute379(ppp);
      result %= 10;
      divide(ppp, 5);
    }
    divide(pp, 2);
  }

  return result;
}

int main() {
  char s[200];
  bigNumber b;
  int count=1;
  while (scanf(" %s", s) ==1) {
    stringToNumber(s, b);
    printf("Instancia %d\n%d\n\n", count, factorial(b));
    count++;
  }
  return 0;
}
