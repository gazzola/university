#include <iostream>

using namespace std;

int main(){

	int hi, mi, hf, mf, rh, rm;
	cin >> hi >> mi >> hf >> mf;

	int ti = (hi * 60) + mi; // in minutes
    int tf = (hf * 60) + mf; // in minutes

    if(tf <= ti)
		tf += 24*60;
	tf = (tf-ti);

	rh = tf/60;
	rm = tf-60 * rh;
	
	cout << "O JOGO DUROU " << rh << " HORA(S) E " << rm << " MINUTO(S)" << endl;

	return 0;
}