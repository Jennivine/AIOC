#include <bits/stdc++.h>
using namespace std;

int N,M;
int size[1005];
int value[1005];

int checked[1005][1005];
int cache[1005][1005];
pair<int, int> path[1005][1005];

int knapsack(int m, int w);
void printPath(int m, int w);
void printPath2(int m, int w);

int main() {
    freopen("knapin.txt", "r", stdin);
    freopen("knapout.txt","w",stdout);

    scanf("%d %d", &N, &M);

	for (int i=1; i<=N; i++) {
		int s,v;
		scanf("%d %d", &s, &v);
		size[i] = s;
		value[i] = v;
	}

	int ans = knapsack(N,M);
    printPath(N,M);
}

void printPath(int m, int w) {
    if (path[m][w] == make_pair(0,0)) {
        return;
    }
    int m_, w_;
    tie(m_, w_) = path[m][w];
    printPath(m_, w_);
    
    if (w != w_) {
        printf("%d\n", m);
    }
}

void printPath2(int m, int w) {
    for (int i=1; i<=m; i++) {
        for (int j=0; j<=w; j++) {
            printf("(%d,%d) path = %d %d\n", i, j, path[i][j].first, path[i][j].second);
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
        path[m][w] = make_pair(m, w-size[m]);
    } else {
        cache[m][w] = b;
        path[m][w] = make_pair(m-1, w);
    }
    
    return cache[m][w];
}
