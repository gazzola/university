#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const int BASE_X = 300;
const int BASE_Y = 420;



int main(){

	int linha[2];
	bool horizontal;
	char direcao;

	string ins;

	while(cin >> ins){

		
		printf("%d %d moveto\n", BASE_X, BASE_Y);
		printf("%d %d lineto\n", BASE_X+10, BASE_Y);

		linha[0] = BASE_X+10;
		linha[1] = BASE_Y;
		horizontal = true;
		direcao = 'D';


		for(char c: ins){

			if(c == 'A'){
				if(horizontal){
					if(direcao == 'D'){
						linha[1] -= 10;
						direcao = 'B';
					}
					else{
						linha[1] += 10;
						direcao = 'C';
					}
				}
				else{
					if(direcao == 'B'){
						linha[0] -= 10;
						direcao = 'E';
					}
					else{
						linha[0] += 10;
						direcao = 'D';
					}
				}
			}
			else{
				if(horizontal){
					if(direcao == 'D'){
						linha[1] += 10;
						direcao = 'C';
					}
					else{
						linha[1] -= 10;
						direcao = 'B';
					}
				}
				else{
					if(direcao == 'B'){
						linha[0] += 10;
						direcao = 'D';
					}
					else{
						linha[0] -= 10;
						direcao = 'E';
					}
				}
			}

			horizontal = !horizontal;
			printf("%d %d lineto\n", linha[0], linha[1]); 
		}


		printf("stroke\nshowpage\n");
	}

	
	return 0;
}