#include <iostream>

using namespace std;


int dayToYear(int *second){
	int h = *second/365;
	*second -= 365*h;  
	return h;
}

int dayToMonth(int *second){
	int m = *second/30;
	*second -= 30*m;
	return m;
}

int main(){

	int n, a, m, d;
	cin >> n;

	a = dayToYear(&n);
	m = dayToMonth(&n);
	d = n;

	cout << a << " ano(s)" << endl
		 << m << " mes(es)" << endl
		 << d << " dia(s)" << endl;

	return 0;
}