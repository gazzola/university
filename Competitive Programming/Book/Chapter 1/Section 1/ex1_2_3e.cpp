#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


class Data{

	public:
		
		int d,m,y;

		Data(int d, int m, int y){
			this->d = d;
			this->m = m;
			this->y = y;
		};

		virtual ~Data(){};

		bool operator < (const Data &x) const{
			if(this->m < x.m)
				return true;
			else if(this->m > x.m)
				return false;

			if(this->d < x.d)
				return true;
			else if(this->d > x.d)
				return false;

			return (this->y < x.y);
		}
};


int main(){

	vector<Data> v;
	int d,m,y;
	while(scanf("%d/%d/%d", &d, &m, &y) != EOF){
		v.push_back(Data(d, m, y));
	}
	
	sort(v.begin(), v.end());

	printf("\n");

	for(int i=0; i<(int) v.size(); i++)
		printf("%d/%d/%d\n", v[i].d, v[i].m, v[i].y);

}