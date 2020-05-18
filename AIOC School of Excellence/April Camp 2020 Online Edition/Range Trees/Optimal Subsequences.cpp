#include <bits/stdc++.h>
using namespace std;

// codeforces problemID 1227 D2
// TODO: Implement a persistent segtree if queries are online

const int MAXN = 2*1e5 + 5;

int arr[MAXN];
int queriesAns[MAXN];

struct QUERY {
	int k, pos, id;

	bool operator < (const QUERY& other) const {
		return (k < other.k);
	}
};

QUERY requests[MAXN];

struct rt{
	rt *lc, *rc;
	int l,r,m;

	rt(int L, int R) {
		l = L;
		r = R;
		m = 0;

		if (L == R) {
			// leaf
		} else {
			int mid = (L+R)/2;
			lc = new rt(L, mid);
			rc = new rt(mid+1, R);
		}
	}

	void update(int index, int v) {
		if (index < l || r < index) {
			return;
		} else if (l == r) {
			m = v;
		} else {
			lc->update(index, v);
			rc->update(index, v);
			m = lc->m + rc->m;
		}
	}

	int query(int index) {
		// do a segtree walk to find the i_th element included
		if (l == r) {
			return l;

		} else if (index <= lc->m) {
			return lc->query(index);
		
		} else {
			index -= lc->m;
			return rc->query(index);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<pair<int,int> > pq;
	
	int n;
	cin >> n;

	// pre-processing using max heap
	for (int i=1; i<=n; i++) {
		int num;
		cin >> num;

		arr[i] = num;
		pq.push(make_pair(num, -i));
	}

	int m;
	cin >> m;
	
	for (int i=1; i<=m; i++) {
		QUERY q;
		cin >> q.k >> q.pos;
		q.id = i;
		
		requests[i] = q;
	}

	sort(requests, requests+m+1);

	rt* RT = new rt(1, n);
	
	int curK = 0;
	for (int i=1; i<=m; i++) {
		int k, target;
		k = requests[i].k;
		target = requests[i].pos;

		for (int j=1; j<=(k-curK); j++) {
			pair<int, int> element = pq.top();
			pq.pop();

			RT->update(-element.second, 1);
		}
		curK = k;

		int index = RT->query(target);
		queriesAns[requests[i].id] =  arr[index];
	}

	for (int i=1; i<=m; i++) {
		cout << queriesAns[i] << "\n";
	}
}
