#include <iostream>

using namespace std;

int secondToDay(int seconds){
    return 
}


int main(){

    int di, hi, mi, si, df, hf, mf, sf;
    string t;

    cin >> t >> di >> hi >> t >> mi >> t >> si;
    cin >> t >> df >> hf >> t >> mf >> t >> sf;

    int tdi = (di * 24 * 3600) + hi*3600 + mi * 60 + si;
    int tdf = (df * 24 * 3600) + hf*3600 + mf * 60 + sf;

    tdf = tdf-tdi;

    int rd = tdf/(24*3600);
    int rh = tdf/3600 - rd*24;
    int rm = tdf/60 - rh*60 - rd*24*60;
    int rs = tdf - rm*60 - rh*3600 - rd*24*3600;

    cout << rd << " dia(s)" << endl;
    cout << rh << " hora(s)" << endl;
    cout << rm << " minuto(s)" << endl;
    cout << rs << " segundo(s)" << endl;

	return 0;
}