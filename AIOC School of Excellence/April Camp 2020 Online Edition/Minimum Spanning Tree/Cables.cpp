#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2005;

struct Edge {
	short u, v;
	int weight;
	bool operator < (const Edge& other) const {
		return (weight < other.weight);
	}
};

int parent[MAXN], N;
ll cost = 0;
vector<Edge> edges(MAXN);

void make_set(int N) {
	for (int i=1; i<=N; i++) {
		parent[i] = i;
	}
}

int union_find(int a) { 
	if (parent[a] == a) return a;

	return parent[a] = union_find(parent[a]);
}

void union_join(Edge e) {
	int a = union_find(e.u);
	int b = union_find(e.v);

	if (a != b) {
		// join the two subtrees
		parent[a] = b;
		cost += e.weight;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("cables.in", "r", stdin);
	freopen("cables.out","w",stdout);

	cin >> N;
	int counter = N-1;
	make_set(N);

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=counter; j++) {
			Edge e;

			cin >> e.u >> e.v >> e.weight;
			edges.push_back(e);
		}
		counter--;
	}

	sort(edges.begin(), edges.end());
	for (auto e: edges) {
		union_join(e);
	}
	
	cout << cost << "\n";
}
