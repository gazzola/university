//#include <iostream>
//#include <iomanip>
#include <cstdio>

using namespace std;


int main(){
	
	int alt, comp;
	while(true){

		//cin >> alt >> comp;
		scanf("%d %d ", &alt, &comp);

		if(alt == 0 && comp == 0)
			break;

		int count=0, last, temp;
		for(int i=0; i<comp; i++){
			//cin >> temp;
			scanf("%d", &temp);

			if(i > 0)
				if(temp > last)
					count += temp-last;

			last = temp;

		}


		if(alt > last)
			count += alt-last;

		//cout << count << endl;
		printf("%d\n", count);

	}

	return 0;
}