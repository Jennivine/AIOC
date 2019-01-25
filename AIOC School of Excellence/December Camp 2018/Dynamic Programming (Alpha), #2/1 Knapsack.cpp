#include <bits/stdc++.h>
using namespace std;

int N,M;
int size[1005];
int value[1005];

int checked[1005][1005];
int cache[1005][1005];
int path[1005][1005];

int knapsack(int m, int w);
void printPath(int m, int w);

int main() {
	scanf("%d %d", &N, &M);

	for (int i=1; i<=N; i++) {
		int s,v;
		scanf("%d %d", &s, &v);
		size[i] = s;
		value[i] = v;
	}

	int ans = knapsack(N,M);
    printf("%d\n", cache[N][M]);
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int knapsack(int m, int w) {
	//TODO: find out a way to record the items taken
	
	if (w==0 || m==0) { return 0; }
	if (w < 0) { return -1e9; }
    if (checked[m][w]) { return cache[m][w]; }
    
    checked[m][w] = 1;
	int a = knapsack(m, w-size[m]) + value[m];
	int b = knapsack(m-1, w);
    if (a > b) {
        cache[m][w] = a;
        path[m][w] = m;
    } else {
        cache[m][w] = b;
        path[m][w] = m-1;
    }
    
    return cache[m][w];
}
