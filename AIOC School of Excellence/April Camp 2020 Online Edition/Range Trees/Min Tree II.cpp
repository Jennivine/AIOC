#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

struct rt {
	rt *lc, *rc;
	int m;
	int l, r;

	rt(int L, int R) {
		l = L;
		r = R;
		m = MAX;
		if (L == R) {
			//leaf
		} else {
			int mid = (L+R)/2;
			lc = new rt(L, mid);
			rc = new rt(mid+1, R);
		}
	}

	void update(int x, int v) {
		if (x < l || r < x) {
			//outside range
			return;
		} else if (l == r) {
			m = v;
		} else {
			lc->update(x, v);
			rc->update(x, v);
			m = min(lc->m, rc->m);
		}
	}

	int query(int ql, int qr) {
		if (qr < l || r < ql) {
			//query misses this node's range
			return MAX;
		} else if (ql <= l && r <= qr) {
			//query domination
			return m;
		} else {
			return min(lc->query(ql,qr), rc->query(ql,qr));
		}
	}
};


int main() {
	int N, Q;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;

	rt* RT = new rt(1, N);
	for (int i=1; i <= N; i++) {
		int d;
		cin >> d;
		RT->update(i,d);
	}

	for (int i=1; i<=Q; i++) {
		char op;
		int p1, p2;

		cin >> op >> p1 >> p2;
		if (op == 'Q') {
			cout << RT->query(p1,p2) << "\n";
		} else {
			RT->update(p1,p2);
		}
	}
}


