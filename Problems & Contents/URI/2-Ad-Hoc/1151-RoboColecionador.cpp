#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;


int main(){

	int linhas, colunas, instrucoes;
	int rotacao, rFinal, x, y;
	char matriz[103][103];
	char carac;
	
	while(true){
		
		scanf("%d %d %d ", &linhas, &colunas, &instrucoes);
		if(linhas==0 && colunas==0 && instrucoes==0)
			break;	

		linhas += 2;
		colunas += 2;


		for(int i=0; i<linhas; i++){
			for(int j=0; j<colunas; j++){
				if(i == 0 || j == 0 || i==linhas-1 || j==colunas-1)
					matriz[i][j] = '#';
				else{
					scanf("%c ", &carac);
					if(carac=='N'){
						rotacao = 0;
						x = i;
						y = j;
						matriz[i][j] = '.';
					}
					else if(carac=='S'){
						rotacao = 2;
						x = i;
						y = j;
						matriz[i][j] = '.';
					}
					else if(carac=='L'){
						rotacao = 1;
						x = i;
						y = j;
						matriz[i][j] = '.';
					}
					else if(carac=='O'){
						rotacao = 3;
						x = i;
						y = j;
						matriz[i][j] = '.';
					}
					else{
						matriz[i][j] = carac;
					}

					
				}
			}
		}

		int figurinhas = 0;
		while(instrucoes--){
			scanf("%c ", &carac);
			if(carac == 'D'){
				if(rotacao == 3)
					rotacao = 0;
				else
					rotacao++;
			}
			else if(carac == 'E'){
				if(rotacao == 0)
					rotacao = 3;
				else
					rotacao--;
			}
			else{

				if(rotacao == 0){ //N
					if(matriz[x-1][y] == '.'){
						x--;
					}
					else if(matriz[x-1][y] == '*'){
						x--;
						figurinhas++;
						matriz[x][y] = '.';
					}
				}
				else if(rotacao == 1){ //L
					if(matriz[x][y+1] == '.'){
						y++;
					}
					else if(matriz[x][y+1] == '*'){
						y++;
						figurinhas++;
						matriz[x][y] = '.';
					}
				}
				else if(rotacao == 2){ //S
					if(matriz[x+1][y] == '.'){
						x++;
					}
					else if(matriz[x+1][y] == '*'){
						x++;
						figurinhas++;
						matriz[x][y] = '.';
					}
				}
				else if(rotacao == 3){ //O
					if(matriz[x][y-1] == '.'){
						y--;
					}
					else if(matriz[x][y-1] == '*'){
						y--;
						figurinhas++;
						matriz[x][y] = '.';
					}
				}
			}
		}

		printf("%d\n", figurinhas);

	}

	return 0;
}
