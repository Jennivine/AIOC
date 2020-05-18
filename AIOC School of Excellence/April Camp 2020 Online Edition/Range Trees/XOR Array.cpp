#include <bits/stdc++.h>
using namespace std;

int N, Q, t[(1<<18) + 5];


void build(int v, int tl, int tr) {
	t[v] = 0;

	if (tl == tr) {
		// leaf
	} else {
		int tm = (tl + tr) / 2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
	}
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (pos < tl || tr < pos) {
		// outside range
		return;
	} else if (tl == tr) {
		t[v] = new_val;
	} else {
		int tm = (tl + tr) / 2;
		
		// lc update
		update(v*2, tl, tm, pos, new_val);
		// rc update
		update(v*2+1, tm+1, tr, pos, new_val);
		
		t[v] = t[v*2]^t[v*2+1];
	}
}

int query(int v, int tl, int tr, int ql, int qr) {
	if (qr < tl || tr < ql) {
		// misses the query range completely
		return 0;
	} else if (ql <= tl && tr <= qr) {
		// query dominates this node's range
		return t[v];
	} else {
		// partial overlap
		int tm = (tl + tr) / 2;
		return query(v*2, tl, tm, ql, qr)^query(v*2+1, tm+1, tr, ql, qr);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;
	
	int v = 1;
	int tl = 0;
	int tr = N-1;

	build(v, tl, tr);

	for (int i=1; i<=Q; i++) {
		int op, p1, p2;
		cin >> op >> p1 >> p2;

		if (op == 0) {
			update(v, tl, tr, p1, p2);
		} else {
			cout << query(v, tl, tr, p1, p2) << "\n";
		}
	}
}
