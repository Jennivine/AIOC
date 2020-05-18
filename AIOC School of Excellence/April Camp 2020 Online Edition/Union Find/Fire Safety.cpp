#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int N, Q;

int parent[MAXN];
int hasWaterMain[MAXN];

void make_set(int N) {
	// initially no buildings are connected, and no buildings have water main 
	for (int i=1; i<=N; i++) {
		parent[i] = i;
		hasWaterMain[i] = 0;
	}
}

int union_find(int a) {
	// find the representative of a set
	if (parent[a] == a) return a;
	
	return parent[a] = union_find(parent[a]);
}

void union_join(int a, int b) {
	// connect two buildings by pipe
	a = union_find(a);
	b = union_find(b);

	if (a != b) {
		parent[b] = a;
		hasWaterMain[a] |= hasWaterMain[b];
	}
}

void build_main(int a) {
	a = union_find(a);
	hasWaterMain[a] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;
	make_set(N);

	for (int i=1; i<=Q; i++) {
		char op;
		int a,b;

		cin >> op;
		if (op == 'P') {
			cin >> a >> b;
			union_join(a,b);
		} else if (op == 'C') {
			cin >> a;
			cout << hasWaterMain[union_find(a)] << "\n";
		} else if (op == 'M') {
			cin >> a;
			build_main(a);
		}
	}
}
