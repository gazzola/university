#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
 
main () {
 
   srand((unsigned int)time((time_t *)NULL));
 
   int in = 0, out = 0;
   double d, x, y, pi;
   long long cont = 10516267;    // ou qualquer outro valor
    
   while (cont-->0) {
 
      x = (double) rand()/ (double)INT_MAX;
      y = (double) rand()/ (double)INT_MAX;
 
      d = x*x + y*y;
 
      (d<=1.0) ? in++ : out++;
 
   }
 
   pi = 4.0 * (float) in / (float) (in + out);
 
   printf ("pi (aprox.) = %2.13f\n", pi);
 
}
