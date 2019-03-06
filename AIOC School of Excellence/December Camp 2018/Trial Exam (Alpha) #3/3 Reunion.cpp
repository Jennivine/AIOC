#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, T, ans;
vector<int> graph[100005];
priority_queue <pii> pq;

int canVisit[100005];

int main() {
	scanf("%d %d %d", &N, &M, &T);
	for (int i=0; i<M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i=0; i<T; i++) {
		int l, k;
		scanf("%d %d", &l, &k);
		pq.push(make_pair(k, l));
	}

	while (pq.size()) {
		pii query = pq.top();
		pq.pop();
		if (! canVisit[query.second]) {
			canVisit[query.second] = 1;
			ans++;
			if (query.first > 0) {
				for (auto s:graph[query.second]) {
					pq.push(make_pair(query.first-1, s));
				}
			}
		}
	}

	printf("%d\n", ans);
}
