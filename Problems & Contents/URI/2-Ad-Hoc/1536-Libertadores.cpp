#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n, m1, v1, m2, v2, a1, a2, p1=0, p2=0;
	char x;
	cin >> n;

	while(n--){

		cin >> m1 >> x >> v1;
		cin >> m2 >> x >> v2;

		a1 = a2 = 0;
		p1 = p2 = 0;

		if(m1 > v1)
			p1 += 3;
		else if(v1 > m1)
			p2 += 3;
		else{
			p1 += 1;
			p2 += 1;
		}

		if(v2 > m2)
			p1 += 3;
		else if(m2 > v2)
			p2 += 3;
		else{
			p1 += 1;
			p2 += 1;
		}


		if(p1 > p2)
			cout << "Time 1" << endl;
		else if(p2 > p1)
			cout << "Time 2" << endl;
		else{
			
			a1 = (m1+v2)-(m2+v1);
			a2 = (m2+v1)-(m1+v2);

			if(a1 > a2)
				cout << "Time 1" << endl;
			else if(a2 > a1)
				cout << "Time 2" << endl;
			else{

				if(v2 > v1)
					cout << "Time 1" << endl;
				else if(v1 > v2)
					cout << "Time 2" << endl;
				else
					cout << "Penaltis" << endl;
			}			
		}

	}

	return 0;
}