#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;


int main(){

	int d,m,y;
	string wd[7] = {"dom", "seg", "ter", "qua", "qui", "sex", "sab"}; 


	while(scanf("%d/%d/%d",&d, &m, &y) != EOF){

		struct tm tm;
		memset(&tm, 0, sizeof(struct tm));

		tm.tm_mday = d;
		tm.tm_mon = m-1;
		tm.tm_year = y-1900;
		mktime(&tm);

		printf("%s\n", wd[tm.tm_wday].c_str());

	}
}