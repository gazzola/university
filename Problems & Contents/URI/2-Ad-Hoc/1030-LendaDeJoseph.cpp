#include <iostream>
#include <iomanip>

using namespace std;



int main(){
	
	int n, qtd, pulo, result, c=1;
	cin >> n;
	while(n--){

		cin >> qtd >> pulo;

		int pos = 0;
		for(int mortos=2; mortos<=qtd; mortos++)
			pos = (pos+pulo) % mortos;
		
		
		cout << "Case " << c++ << ": " << pos+1 << endl;
	}

	return 0;
}


/*


pos = 0
m = 2
pulo = 2

0 | 1 | 2 | 3 | 4 |
    x       



pos = 0
m = 3
pulo = 2

0 | 2 | 3 | 4 |
	    x



pos = 2
m = 4
pulo = 2

0 | 2 | 4 |
x



pos = 1
m = 5
pulo = 2

2 | 4 |
    x



pos = 3

2 |

*/