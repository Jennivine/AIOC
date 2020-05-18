#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100005;

int parent[MAXN * 2], last[MAXN], persistent[MAXN * 2], N, M;

void make_set(int N) {
	for (int i=1; i<=(MAXN*2 - 1); i++) {
		if (i <= N) {
			last[i] = i;
			parent[i] = i;
		}
		persistent[i] = i;
	}
}

int union_find(int a){
	if (a == persistent[a]) return a;

	return persistent[a] = union_find(persistent[a]);
}

void union_join(int a, int b) {
	persistent[union_find(a)] = union_find(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	make_set(N);
	int vertexCount = N;
	
	for (int i=1; i<=M; i++) {
		char op;
		int a,b;

		cin >> op;
		if (op == 'E') {
			cin >> a >> b;
			union_join(last[a],last[b]);
			last[a] = ++vertexCount;
			parent[vertexCount] = a;
		} else {
			cin >> a;
			cout << parent[union_find(a)] << "\n";
		}
	}
}

