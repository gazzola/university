
/*
* * * * * * * * * * * * *
* Author: Tiago Togores *
* * * * * * * * * * * * *
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof a)
#define REP(i, n) for (auto i = 0; i < (n); i++)
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORT(it, l) for (auto it = (l).begin(); it != (l).end(); it++)
#define VALID(i, j, n, m) (0 <= (i) && (i) < (n) && 0 <= (j) && (j) < (m))
#define EPSILON 1e-6
#define INF 1000000000
#define MOD 1000000007
#define PI M_PI

#define SCI(n) scanf("%d", &(n))
#define SCL(n) scanf("%lld", &(n))
#define SCF(f) scanf("%f", &(f))
#define SCD(d) scanf("%lf", &(d))
#define SCS(s) scanf("%s", (s))
#define SCW(n) while (SCI(n) != EOF && (n))
#define SCR(n) for (SCI(n); (n)--;)
#define READLINE(line) fgets((line), sizeof (line), stdin)
#define WREADLINE(line) while (READLINE(line), !feof(stdin))
#define NEWLINE "\n"

///////////////////////////////

void print(int num, int c, int d)
{
   if (num <= 2) {   
      REP (i, num)
         putchar(c);
      return;
   }
   while (num > 255) {
      putchar(d);
      putchar(255);
      num -= 255;   
   }
   if (num > 0) {
      putchar(d);
      putchar(num);
   }
}

int main()
{
_
   int t;
   while (SCI(t) != EOF) {
      getchar();
      while (t--) {
         int zeros = 0, spaces = 0;
         for (int c; (c = getchar()) != EOF;) {
            if (c == '\n' || (c != '0' && !isspace(c))) {
               if (zeros != 0) {
                  print(zeros, '0', '#');
                  zeros = 0;   
               }
               else if (spaces != 0) {
                  print(spaces, ' ', '$');
                  spaces = 0;   
               }
               putchar(c);
               if (c == '\n')
                  break;
            }
            else if (c == '0') {
               if (spaces != 0) {
                  print(spaces, ' ', '$');
                  spaces = 0;
               }
               zeros++;
            }
            else {
               if (zeros != 0) {
                  print(zeros, '0', '#');
                  zeros = 0;   
               }
               spaces++;
            }
         }
      }
   }
   return 0;
}