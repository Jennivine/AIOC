#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, E, X, K;
vector<int> adjList[100005];

int visited[100005];
int ans;

void DFS(int start, int movesLeft);

int main() {
	freopen("evadingin.txt", "r", stdin);
	freopen("evadingout.txt","w",stdout);

	scanf("%d %d %d %d", &N, &E, &X, &K);
	for (int i=0; i<E; i++) {
		int a,b;
		scanf("%d %d",  &a, &b);
		
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	DFS(X, K);

	printf("%d\n", ans);
}

void DFS(int start, int movesLeft) {
	visited[start] = 1;

	if (movesLeft %2 == 0) { 
		ans++;
	}

	for (auto i: adjList[start]) {
		if (!visited[i]) 
			DFS(i, movesLeft-1);
	}
}
