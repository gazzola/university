#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>

using namespace std;



int main(){
 
	
	map<string, string> tradutor;
	tradutor["brasil"] = "Feliz Natal!";
	tradutor["alemanha"] = "Frohliche Weihnachten!";
	tradutor["austria"] = "Frohe Weihnacht!";
	tradutor["coreia"] = "Chuk Sung Tan!";
	tradutor["espanha"] = "Feliz Navidad!";
	tradutor["grecia"] = "Kala Christougena!";
	tradutor["estados-unidos"] = "Merry Christmas!";
	tradutor["inglaterra"] = "Merry Christmas!";
	tradutor["australia"] = "Merry Christmas!";
	tradutor["portugal"] = "Feliz Natal!";
	tradutor["suecia"] = "God Jul!";
	tradutor["turquia"] = "Mutlu Noeller";
	tradutor["argentina"] = "Feliz Navidad!";
	tradutor["chile"] = "Feliz Navidad!";
	tradutor["mexico"] = "Feliz Navidad!";
	tradutor["antardida"] = "Merry Christmas!";
	tradutor["canada"] = "Merry Christmas!";
	tradutor["irlanda"] = "Nollaig Shona Dhuit!";
	tradutor["belgica"] = "Zalig Kerstfeest!";
	tradutor["italia"] = "Buon Natale!";
	tradutor["libia"] = "Buon Natale!";
	tradutor["siria"] = "Milad Mubarak!";
	tradutor["marrocos"] = "Milad Mubarak!";
	tradutor["japao"] = "Merii Kurisumasu!";

	string pais;
	while(cin >> pais){
		if(tradutor.count(pais) > 0)
			cout << tradutor[pais] << endl;
		else
			cout << "--- NOT FOUND ---" << endl;
	}
 
	return 0;
}