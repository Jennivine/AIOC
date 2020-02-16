#include <bits/stdc++.h>
using namespace std;

int N; //number of nodes
int P; //number of edges

vector<pair<int, int> > ANU[505];
int checked[505];

int DFS(int x, int y, int w);

int main() {
	freopen("catsin.txt","r",stdin);
	freopen("catsout.txt","w",stdout);
	scanf("%d", &N);
	scanf("%d", &P);

	for (int i=0; i<P; i++) {
		int X,Y,K;
		scanf("%d %d %d", &X, &Y, &K);
		ANU[X].push_back(make_pair(Y, K));
		ANU[Y].push_back(make_pair(X, K));
	}

	int B,C;
	scanf("%d %d", &B, &C);	

	int lo = 0;
	int hi = 1e9;
	
	while (lo != hi) {
		//do binary search on minimum maximum cost
		int mid = (lo+hi)/2;	
		
		if (DFS(B, C, mid)){
			hi = mid;
		} else {
			lo = mid+1;
		}

		//cleanup
		for (int i=1; i<=N; i++) {
			checked[i] = 0;
		}
	}
	
	printf("%d\n", lo);
}

int DFS(int x, int y, int w) {
	// returns 1 is there's a path, 0 otherwise using only paths of weight w
	if (checked[x]) {return 0;}
	if (x == y) {return 1;}
	
	checked[x] = 1;
	
	for (auto n:ANU[x]){
		int node = n.first;
		int cats = n.second;
		if (cats <= w && DFS(node,y,w)) {return 1;}
	}
	
	return 0;
}
