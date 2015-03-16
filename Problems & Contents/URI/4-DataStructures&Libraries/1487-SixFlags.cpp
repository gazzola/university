#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


typedef pair<int, int> ii;


// bool orderBy(const ii &x, const ii &y){
// 	double a = (double) x.second / x.first;
// 	double b = (double) y.second / y.first;

// 	if(a < b)
// 		return true;
// 	else if(a > b)
// 		return false;
// }



int main(){
 	
 	int n, t, d, p, h=1;
 	double x;

 	while(scanf("%d %d", &n, &t) and n > 0){

 		vector<ii> brinquedos;

 		while(n--){
 			scanf("%d %d", &d, &p);
 			brinquedos.push_back(ii(d, p));
 		}


 		// sort(brinquedos.begin(), brinquedos.end(), orderBy);

 		int res = 0, td=0;
 		while(td < t){
 			
 			
 			int mpos = -1;
 			double maior = 0;

 			for(int i=0; i<(int) brinquedos.size(); i++){
				x = (double) brinquedos[i].second / brinquedos[i].first;

 				if(x > maior and td + brinquedos[i].first <= t){
 					maior = x;
 					mpos = i;
 				}

 			}

 			if(mpos == -1)
 				break;

 			// printf("%d\n", brinquedos[mpos].second);
 			res += brinquedos[mpos].second;
 			td += brinquedos[mpos].first;
 		}



 		printf("Instancia %d\n%d\n\n", h++, res);
 	}

 
	return 0;
}