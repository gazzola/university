#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	
	double avN, n1, n2, n3, n4, ne;
	cin >> n1 >> n2 >> n3 >> n4;

	avN = (2*n1 + 3*n2 + 4*n3 + n4)/10.0;
	
	cout << fixed << setprecision(1);
	cout << "Media: " << avN << endl;

	if(avN >= 7.0)
		cout << "Aluno aprovado." << endl;
	else if(avN < 5)
		cout << "Aluno reprovado." << endl;
	else{
		cout << "Aluno em exame." << endl;
		cin >> ne;
		
		cout << "Nota do exame: " << ne << endl;
		avN = (ne+avN)/2.0;
		
		if(avN < 5)
			cout << "Aluno reprovado." << endl;
		else
			cout << "Aluno aprovado." << endl;

		cout << "Media final: " << avN << endl;
	}

	return 0;
}