#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
 
using namespace std;
 
bool ehSub(char *str1, char *str2){
 
	int i = 0;
	//int k = strlen(str1);
	for(int j=0; str1[j]!='\0'; j++){
		if(str1[j] == str2[i])
			i++;
		if(str2[i] == '\0')
			return true;
	}
 
	return false;
}
 
 
 
int main(){
 
	int n, q;
	char str1[100001];
	char str2[100001];
 
	scanf("%d", &n);
	while(n--){
 
		scanf("%s", str1);
		scanf("%d", &q);
		while(q--){
			scanf("%s", str2);
			if(ehSub(str1, str2))
				printf("Yes\n");
			else
				printf("No\n");
		}
 
 
	}
 
	return 0;
}