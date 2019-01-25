#include <bits/stdc++.h>
using namespace std;

int N;
int dishes[100005];

int main(){
	freopen("nomin.txt","r",stdin);
	freopen("nomout.txt","w",stdout);

	scanf("%d", &N);

	for (int i=0; i<N; i++){
		int weight;
		scanf("%d", &weight);
		dishes[i] = weight;
	}

	int satisfiedCount = 1; //the eldest hippo will always be satisfied
	int startingW = dishes[0];
	int currFood = 0;

	for (int i=1; i<N; i++) {
		currFood += dishes[i];
		if (currFood >= startingW) {
			satisfiedCount++;
			startingW = currFood;
			currFood = 0;
		}
	}

	printf("%d\n", satisfiedCount);
}


