#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
typedef long long ll;

int jump[maxn][20];
vector<pair<int, ll> > adj[maxn];
int hei[maxn], n, q;
ll dis[maxn];

void dfs(int a, int par, int h, ll d) {
	if (hei[a]) return;
	hei[a] = h;
	dis[a] = d;
	jump[a][0] = par;
	for (auto b: adj[a]) {
		dfs(b.first, a, h+1, d+b.second);
	}
}

int lca(int a, int b) {
	// first bring a and b to the same height
	for (int i=19; i>=0; i--) {
		if (hei[jump[a][i]] >= hei[b]) a = jump[a][i];
		if (hei[jump[b][i]] >= hei[a]) b = jump[b][i];
	}

	// then find the LCA of a and b
	for (int i=19; i>=0; i--) {
		if (jump[a][i] != jump[b][i]) a = jump[a][i], b = jump[b][i];
	}

	if (a == b) return a;
	return jump[a][0];
}

int main() {
	freopen("jim.in", "r", stdin);
	freopen("jim.out","w",stdout);

	scanf("%d %d", &n, &q);

	// construct tree
	for (int i=0; i<n-1; i++) {
		int a, b;
		ll c;

		scanf("%d %d %lld", &a, &b, &c);

		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}

	// city 1 as the root because root is arbituary
	dfs(1, 0, 1, 0);

	// initialise jump pointers
	for (int j=1; j<20; j++) {
		for (int i=1; i<=n; i++) {
			jump[i][j] = jump[jump[i][j-1]][j-1];
		}
	}

	// query time
	for (int i=1; i<=q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		int intersect = lca(a,b);
		ll ans = dis[a] + dis[b] - 2*dis[intersect];

		printf("%lld\n", ans);
	}
}
