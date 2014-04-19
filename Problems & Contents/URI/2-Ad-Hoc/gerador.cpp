#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(){
        
    srand(time(NULL));

    int n = 50;

    while(n--){
    	for(int i=0; i<9; i++){
	    	int x = (rand()%8)+1;	
	    	char c = 96+(rand()%8)+1;
	    	printf("%d%c\n", x, c);
    	}
    }

    printf("0\n");
    
    
    return 0;    
}