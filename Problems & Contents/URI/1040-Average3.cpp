#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	
	double avN, n1, n2, n3, n4, ne;

	cin >> n1 >> n2 >> n3 >> n4;

	avN = (2*n1 + 3*n2 + 4*n3 + n4)/10;
	cout << fixed << setprecision(1) << "Media: " << avN << endl;

	if(avN >= 7)
		cout << "Aluno aprovado." << endl;
	else if(avN < 5)
		cout << "Aluno reprovado." << endl;
	else{
		cout << "Aluno em exame." << endl;
		cin >> ne;
		cout << fixed << setprecision(1) << "Nota do exame: " << ne << endl;
		avN = (ne+avN)/2;
		if(avN >= 5)
			cout << "Aluno aprovado." << endl;
		else
			cout << "Aluno reprovado." << endl;

	}

	cout << fixed << setprecision(1) << "Media final: " << avN << endl;

	return 0;
}