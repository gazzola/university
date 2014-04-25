#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char const *argv[]){

	int linecount = 1;
	string line1, line2;
	bool ok = true;

	ifstream infile1(argv[1]);
	ifstream infile2(argv[2]);


	if(infile1 && infile2){
		while(getline(infile1 , line1) && getline(infile2 , line2)){
			if(line1 != line2){
				ok = false;
				break;
			}
			linecount++ ;
		}

		if(ok)
			cout << "Nenhum erro, manda bala!" << endl;
		else
			cout << "Erro na comparacao: " << linecount << endl;
	}

	infile1.close();
	infile2.close();


	return 0 ;
}