#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	string months[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int m;
    
    cin >> m;
    cout << months[m-1] << endl;

	return 0;
}