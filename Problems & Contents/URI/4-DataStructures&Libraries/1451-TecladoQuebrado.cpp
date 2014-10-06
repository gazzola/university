#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

using namespace std;

const int HOME = 1;
const int END = 2;


int main(){
 
	char palavra[100005];
	while(scanf("%s", palavra) != EOF){

		string s_end = "";
		string s_home = "";
		string s_final = "";

		int flag = END;
		
		// da pra fazer um deque xD
		for(int i=0; palavra[i]!='\0'; i++){

			if(palavra[i] == '['){
				s_final = s_home+s_final+s_end;
				
				s_home = "";
				s_end = "";

				flag = HOME;
				continue;
			}
			else if(palavra[i] == ']'){
				s_final = s_home+s_final+s_end;
				
				s_end = "";
				s_home = "";

				flag = END;
				continue;
			}


			if(flag == END)
				s_end += palavra[i];
			else
				s_home += palavra[i];

		}


		s_final = s_home+s_final+s_end;
		printf("%s\n", s_final.c_str());

	}

 
	return 0;
}