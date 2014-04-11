#include <iostream>

using namespace std;


int secondToHour(int *second){
	int h = *second/3600;
	*second -= 3600*h;  
	return h;
}

int secondToMinute(int *second){
	int m = *second/60;
	*second -= 60*m;
	return m;
}

int main(){

	int n, h, m, s;
	cin >> n;

	h = secondToHour(&n);
	m = secondToMinute(&n);
	s = n;

	cout << h << ":" << m << ":" << s << endl;

	return 0;
}