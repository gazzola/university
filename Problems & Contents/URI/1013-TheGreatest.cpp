#include <iostream>
#include <cmath>

using namespace std;

int greatestNumber(int a, int b){
	return (a+b + abs(a-b))/2;
}


int main(){

	int A, B, C, bigger;
	cin >> A >> B >> C;

	bigger = greatestNumber(A, B);
	bigger = greatestNumber(bigger, C);

	cout << bigger << " eh o maior" << endl;

	return 0;
}