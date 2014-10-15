#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <set>
#include <string>
#include <locale>
 
 
using namespace std;
 
 
int main(){
 
	char palavra[201];
	set<string> dicio;
	set<string>::iterator it;
 
	while(scanf("%[a-zA-Z]", palavra) != EOF){
 
		//printf("%s\n", palavra);
		string s = palavra;
 
		//while(!isalpha(getc(stdin)));
 
		char c;
		scanf("%c", &c);
		//if(c <= (int)'z' and c >= (int)'A')
		//  s += c;
 
		 
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		dicio.insert(s);
	}
	 
	for(it=dicio.begin(); it!=dicio.end(); ++it){
		printf("%s\n", (*it).c_str());
	}
		 
		//cout << *it << endl;
 
	return 0;
}