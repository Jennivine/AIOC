#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, D, a[50005], b[50005], ans, impossible, seen[50005], cnts[2];

vector<int> posWeed[100005];
vector<pii> graph[50005]; // each element in the graph stores the two nodes in graph 

void dfs(int x, int col) {
	seen[x] = 1;
	cnts[col]++;

	for (pii p: graph[x]) {
		int v = p.first;
		if (!seen[v]) dfs(v, col ^ p.second);
	}
}


int main() {
	scanf("%d %d", &N, &D);

	for (int i=1; i<=N; i++) {
		scanf("%d", a+i);
		posWeed[a[i]].push_back(i);
		
		if (posWeed[a[i]].size() > 2) impossible = 1;
	}

	for (int i=1; i<=N; i++) {
		scanf("%d", b+i);
		posWeed[b[i]].push_back(-i); // negative index = col on the second row

		if (posWeed[b[i]].size() > 2) impossible = 1;
	}

	if (impossible) {
		printf("-1\n");
	} else if (D == 0) {
		int upperCount = 0, lowerCount = 0;
		for (int i=1; i<=100000; i++) {
			if (posWeed[i].size() == 2) {
				if (posWeed[i][0] > 0 && posWeed[i][1] > 0) upperCount++;
				else if (posWeed[i][0] < 0 && posWeed[i][1] < 0) lowerCount++;
			}
		}
		printf("%d\n", max(upperCount, lowerCount));
	} else {
		// graph and shadow graph here we go
		for (int i=1; i<=100000; i++) {
			if (posWeed[i].size() == 2) {
				int x = abs(posWeed[i][0]), y = abs(posWeed[i][1]);
				long long prod = ((long long)posWeed[i][0]) * (posWeed[i][1]);

				if (prod > 0) {
					// two of the same type of weed in one row
					graph[x].push_back(make_pair(y,1));
					graph[y].push_back(make_pair(x,1));
				} else {
					// two of the same type of weed in different rows
					graph[x].push_back(make_pair(y,0));
					graph[y].push_back(make_pair(x,0));
				}
			}
		}
			
		for (int i=1; i<=N; i++) {
			if (!seen[i]) dfs(i, 0);
			ans += min(cnts[0],cnts[1]);
			cnts[0] = cnts[1] = 0;
		}
		printf("%d\n", ans);
	}
}

