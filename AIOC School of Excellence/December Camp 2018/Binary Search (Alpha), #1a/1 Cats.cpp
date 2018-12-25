#include <bits/stdc++.h>
using namespace std;

int N; //number of nodes
int P; //number of edges

vector<int> ANU[505];
pair<int, pair<int, int> > edges[100005]; // <K,<X,Y> >
int checked[505];

int DFS(int x, int y);

int main() {
	freopen("catsin.txt","r",stdin);
	//freopen("catsout.txt","w",stdout);
	scanf("%d", &N);
	scanf("%d", &P);

	for (int i=0; i<P; i++) {
		int X,Y,K;
		scanf("%d %d %d", &X, &Y, &K);

		edges[i] = make_pair(K,make_pair(X,Y));
	}

	sort(edges, edges+P);
	
	int B,C;
	scanf("%d %d", &B, &C);	

	int lo = 0;
	int hi = 1e9;
	while (lo != hi) {
		//do binary search on minimum maximum cost
		int mid = (lo+hi)/2;	
		
		//construct graph using only edges <= mid
		int i = 0;
		while (edges[i].first <= mid && i<N){
			int x = edges[i].second.first;
			int y = edges[i].second.second;
			ANU[x].push_back(y);
			ANU[y].push_back(x);
			i++;
		}
		
		/*debug
		printf("mid:%d\n",mid);
		for (int i=0; i<N; i++){
			if (ANU[i].empty()) continue;
			for (auto n:ANU[i]){
				printf("%d %d\n", i,n);
			}
		}*/

		if (DFS(B,C)){
			hi = mid;
		} else {
			lo = mid+1;
		}

		//cleanup
		for (int i=0; i<N; i++) {
			ANU[i].clear();
			checked[i] = 0;
		}
	}
	printf("%d\n", lo);
}

int DFS(int x, int y) {
	//returns 1 is there's a path, 0 otherwise
	if (checked[x]) {return 0;}
	if (x == y) {return 1;}
	checked[x] = 1;
	for (auto n:ANU[x]){
		if (DFS(n,y)) {return 1;}
	}
	return 0;
}
