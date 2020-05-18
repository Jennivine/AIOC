#include <bits/stdc++.h>
using namespace std;

const int MIN = 0;

struct rt {
	int r, l, m;
	rt *lc, *rc;
	int dirty; // if dirty = MIN, there is nothing to do


	void clean() {
		if (dirty != MIN) {
			m = dirty;
			if (l != r) {
				lc->m = dirty;
				rc->m = dirty;
				lc->dirty = dirty;
				rc->dirty = dirty;
			}
			dirty = MIN;
		}
	}

	rt(int L, int R) {

		l = L;
		r = R;
		m = MIN;
		dirty = MIN;

		if (L == R) {
			//leaf
		} else {
			int mid = (L+R)/2;
			lc = new rt(L, mid);
			rc = new rt(mid+1, R);
		}
	}


	void update_set(int ul, int ur, int v) {
		clean();

		if (ur < l || r < ul) {
			return;
		} else if (ul <= l && r <= ur) {
			dirty = v;
			m = v;
		} else {
			lc->update_set(ul, ur, v);
			rc->update_set(ul, ur, v);
			m = max(lc->m, rc->m);
		}		
	}

	int query_max(int ql, int qr) {
		clean();

		if (qr < l || r < ql) {
			return MIN;
		} else if (ql <= l && r <= qr) {
			return m;
		} else {
			return max(lc->query_max(ql, qr), rc->query_max(ql, qr));
		}	
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;

	rt* RT = new rt(0, N-1);

	for (int i=0; i<Q; i++) {
		char op;
		int p1, p2, p3;

		cin >> op;

		if (op == 'S') {
			cin >> p1 >> p2 >> p3;
			RT->update_set(p1, p2, p3);

		} else if (op == 'M') {
			cin >> p1 >> p2;
			cout << RT->query_max(p1, p2) << "\n";
		}
	}
}


