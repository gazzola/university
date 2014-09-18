#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
 
int main(){
 
	int n;
	int ax, ay, bx, by, cx, cy, dx, dy, rx, ry;

	scanf("%d", &n);
	
	while(n--){
		scanf("%d %d %d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy, &rx, &ry);

		short int ok = 0;
		if(rx >= ax and rx >= dx)
			if(rx <= bx and rx <= cx)
				if(ry >= ay and ry >= by)
					if(ry <= cy and ry <= dy)
						ok = 1;

		printf("%hd\n", ok);
		
	}
 
 
	return 0;
}