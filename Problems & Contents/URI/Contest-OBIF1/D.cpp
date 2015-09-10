#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long unsigned int llu;

// structs and typedefs
typedef struct triple{
	int first, second, third;

	triple(){}
	triple(int f, int s, int t){
		first = f;
		second = s;
		third = t;
	}
}triple;


bool orderBy(triple &i, triple &j){
	if(i.first < j.first)
		return true;
	if(i.second < j.second)
		return true;
	return i.third < j.third;
}



int backtrack(int rw, int ld, int rd){


	int pos = (1 << 20) - 1;
	while(pos){
		int p = pos & -pos;
		pos -= p;
		printf("ads\n");
	}
}


int pras[3];
vector<triple> cards;

bool test(int n){
	for(int i=1; i<(1<<n); i++){
		int sum = 0;

		vector<int> q;
		for(int j=0; j<n; j++){
			if(i & (i<<j)){
				q.push_back(j);
				sum += cards[j].first;
			}
		}
		if(sum == pras[0]){

			int x,y;
			x = y = 0;

			for(int j=0; j<q.size(); j++){
				x += cards[q[j]].second;
				y += cards[q[j]].third;
			}
			
			if(x == pras[1] and y == pras[2] and q.size() > 1)
				return true;
		}
	}

	return false;
}


// bool ver(int n){
// 	std::string bitmask(K, 1); // K leading 1's
//     bitmask.resize(N, 0); // N-K trailing 0's
 
//     // print integers and permute bitmask
//     do {
//         for (int i = 0; i < N; ++i) // [0..N-1] integers
//         {
//             if (bitmask[i]) std::cout << " " << i;
//         }
//         std::cout << std::endl;
//     } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
// }


// bool isSubsetSum(vector<triple> &set, int n, int sum)
// {
//    // Base Cases
//    if (sum == 0)
//      return true;
//    if (n == 0 && sum != 0)
//      return false;
 
//    // If last element is greater than sum, then ignore it
//    if (set[n-1].first > sum)
//      return isSubsetSum(set, n-1, sum);
 
//    /* else, check if sum can be obtained by any of the following
//       (a) including the last element
//       (b) excluding the last element   */
//    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1].first);
// }


bool ok = false;
void find(vector<triple> &set, int n, int currSum, int index, int sum, int *solution) {
	if (currSum == sum) {
		// printf("\nSum found\n");
		int x,y;
		x = y = 0;

		bool foioutro = false;
		int last = 0;
		for (int i = 0; i < n; i++) {
			
			if(solution[i] == 1){
				x += set[i].second;
				y += set[i].third;

				if(i != last)
					foioutro = true;

				last = i;
				// printf("%d ", set[i].first);
			}
		}

	
		if(x == pras[1] and y == pras[2] and foioutro){
			ok = true;
			return ;
		}

	} 
	else if (index == n) {
		return;
	} 
	else {
		solution[index] = 1;// select the element
		currSum += set[index].first;
		find(set, n, currSum, index + 1, sum, solution);

		solution[index] = 0;// do not select the element
		currSum -= set[index].first;
		find(set, n, currSum, index + 1, sum, solution);
	}
	return;
}


int main(){

	int a,b,c;
	
	// int cards[21][3];
	int n;
	int solution[21]; 
	memset(solution, 0, sizeof(solution));


	scanf("%d", &n);
	scanf("%d %d %d", &pras[0], &pras[1], &pras[2]);

	for(int i=0; i<n; i++){
		scanf("%d %d %d", &a, &b, &c);
		cards.push_back(triple(a,b,c));
	}

	// sort(cards.begin(), cards.end(), orderBy);

	// backtrack(0,0,0);
	// bool ok = test(n);

	// bool ok = isSubsetSum(cards, n, pras[0]);



	find(cards, n, 0, 0, pras[0], solution);
	// bool ok;
	if(ok)
		printf("Y\n");
	else
		printf("N\n");




	

	

	return 0;
}
