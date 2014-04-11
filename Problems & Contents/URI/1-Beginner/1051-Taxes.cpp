#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	double salary, result=0, ratio=1;

    cin >> salary;

    if(salary <= 2000){
        cout << "Isento" << endl;
    }
    else{

        if(salary > 2000 && salary <= 3000){
            salary -= 2000;
            ratio = 0.08;
            result += salary*ratio;
        }
        else if(salary > 3000 && salary <= 4500){
            salary -= 2000;
            ratio = 0.08;
            result += 1000*ratio;

            salary -= 1000;
            ratio = 0.18;
            result += salary*ratio;
        }
        else if(salary > 4500){
            salary -= 2000;
            ratio = 0.08;
            result += 1000*ratio;

            salary -= 1000;
            ratio = 0.18;
            result += 1500*ratio;

            salary -= 1500;
            ratio = 0.28;
            result += salary*ratio;
        }

        
        cout << fixed << setprecision(2);
        cout << "R$ " << result << endl;

    }

	return 0;
}