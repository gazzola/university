#include <stdio.h>
#include <string.h>
  
#define MAXB 128
#define MAXF 512
  
typedef int big[MAXB];
  
/* b = 0 */
void big_zero (big b){
	int i;
	for (i=0 ; i<MAXB ; i++)
		b[i] = 0;
}
  

/* b = s */
void big_from_string (char *s, big b){
	int i, len=strlen(s);
	big_zero (b);
	for (i=len-1 ; i>=0 ; i--)
		b[i] = *s++ - '0';
}
  

/* c = a + b */
void big_add (big a, big b, big c){
	int i, carry=0;
	for (i=0 ; i<MAXB ; i++){
		c[i] = carry + a[i] + b[i];
		carry = c[i] / 10;
		c[i] %= 10;
	}
}


/* a <=> b */
int big_cmp (big a, big b){
	int i;
	for (i=MAXB-1 ; i>=0 ; i--)
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return -1;
	return 0;
}
  
big fibs[MAXF];
  

/* precalculate enough fibonacci numbers by dynamic programming */
void calc_fibs ()
{
  int i;
  big_zero (fibs[0]);
  fibs[0][0] = 1;
  big_zero (fibs[1]);
  fibs[1][0] = 2;
  for (i=2 ; i<MAXF ; i++)
	big_add (fibs[i-2], fibs[i-1], fibs[i]);
  //assert (!fibs[i-1][MAXB-1]);
}
  
int buscaBin1(int ini, int fim, big &ba){
  int med=0;
  while(fim >= ini){
 
	med = (ini+fim)/2;
	//printf("%d ", med);
 
	int cp1 = big_cmp(fibs[med], ba);
	int cp2 = big_cmp(fibs[med-1], ba);
 
	if(cp1 >= 0 and cp2 < 0)
	  break;
	 
	if(cp1 > 0 or cp2 > 0)
	  fim = med - 1;
	else
	  ini = med + 1;
  }
 
  return med;
}
 
 
 
int main (){
	
  //assert (in != NULL);
  calc_fibs();
  while (1){
char sa[MAXB], sb[MAXB];
big ba, bb, bz;
int ia, ib;
fscanf (stdin, " %s %s ", sa, sb);
big_from_string (sa, ba);
big_from_string (sb, bb);
//assert (big_cmp (ba, bb) <= 0);

/* check for end of input */
big_zero (bz);
if (! big_cmp(ba, bz) && ! big_cmp(bb,bz)) break;

/* search lower bound */


//printf("\n");
ia = buscaBin1(0, MAXF-1, ba);


//for (ia=0 ; ia<MAXF ; ia++)
//  if (big_cmp (fibs[ia], ba) >= 0) break;

//assert (ia<MAXF);

/* search upper bound */
for (ib=ia; ib<MAXF ; ib++)
if (big_cmp (fibs[ib], bb) > 0) break;
//ib = buscaBin2(ia, MAXF-1, bb);

//assert (ib<MAXF);

//printf("%d %d\n", ia, ib);

/* number of fibs is the difference */
printf ("%d\n", ib-ia);
  }
  
  return 0;
}