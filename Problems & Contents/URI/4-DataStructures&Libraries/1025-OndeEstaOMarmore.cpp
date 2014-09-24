#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
 
using namespace std;
 
template<class Iter, class T>
Iter binary_find(Iter begin, Iter end, T val){
	// Finds the lower bound in at most log(last - first) + 1 comparisons
	Iter i = std::lower_bound(begin, end, val);
 
	if (i != end && !(val < *i))
		return i; // found
	else
		return end; // not found
}
 
int procurar(vector<int> &marmores, int x){
	vector<int>::iterator it;
	int count = 1;
	for(it=marmores.begin(); it!=marmores.end(); ++it){
		if(*it == x)
			return count;
		count++;
	}
 
	return 0;
}
 
int main(){
 
	int n, q, x;
	vector<int>::iterator it;
 
	int count = 1;
	while(true){
 
		//set<int> marmores;
		vector<int> marmores;
 
		scanf("%d %d", &n, &q);
		if(n == q and q == 0)
			break;
 
		while(n--){
			scanf("%d", &x);
			marmores.push_back(x);
		}
 
		sort(marmores.begin(), marmores.end());
 
		printf("CASE# %d:\n", count);
		while(q--){
			scanf("%d", &x);
			it = binary_find(marmores.begin(), marmores.end(), x);
			if(it != marmores.end()){
				int y = distance(marmores.begin(), it)+1;
				printf("%d found at %d\n", x, y);
			}
			else{
				printf("%d not found\n", x);
			}
		}
		 
		count++;
	}
 
	return 0;
}