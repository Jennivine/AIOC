#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int parent[MAXN];

void make_set(int N) {
	for (int i=1; i<=N; i++) {
		parent[i] = i;
	}
}

int find_set(int v) {
	if (parent[v] == v) return v;

	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		parent[b] = a;
	}
}

char query(int a, int b) {
	int parent1 = find_set(a), parent2 = find_set(b);

	if (parent1 == parent2) return 'Y';
	
	return 'N';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("noinu.in", "r", stdin);
	freopen("noinu.out","w",stdout);

	int N, Q;
	cin >> N >> Q;

	make_set(N);

	for (int i=1; i<=Q; i++) {
		char op;
		int a, b;
		cin >> op >> a >> b;

		if (op == 'j') {
			union_sets(a,b);
		} else if (op == 's') {
			cout << query(a,b) << "\n";
		}
	}
}
