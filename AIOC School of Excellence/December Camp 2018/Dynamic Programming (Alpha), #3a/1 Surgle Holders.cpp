#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree[100005];
pair<int, int> best[100005]; //best[i] gives the max no. inspectors given i as a root, as well as whether the i_th node has an inspector

void solve(int node);

int main() {
	freopen("snurgle.in", "r", stdin);
	freopen("snurgle.out","w",stdout);

	scanf("%d", &n);
	for (int i=1; i<n; i++) {
		int node;
		scanf("%d", &node);
		tree[node].push_back(i);
	}

	solve(n);
	printf("%d\n", best[n]);
}

void solve(int node) {	
	if (tree[node].empty()) {
		// base case
		best[node] = make_pair(1, 1);
	}

	int sum = 0;
	int canTake = 1;
	for (auto y: tree[node]) {
		solve(y);
		sum += best[y].first;
		if (best[y].second == 1) {
			canTake = 0;
		}
	}

	if (canTake) {
		sum++;
		best[node] = make_pair(sum, 1);
	} else {
		best[node] = make_pair(sum, 0);
	}
}




