#include <bits/stdc++.h>
using namespace std;

int p, j, A, B;
bool pushed[1000005];
int dist[1000005], paths[1000005], previous[1000005];
vector <int> edges[1000005];
queue <int> q;

void findPath(int breadcrumb, int index);

int main() {
	freopen("frogsin.txt", "r", stdin);
	freopen("frogsout.txt","w",stdout);

	scanf("%d %d", &p, &j);
	scanf("%d %d", &A, &B);

	for (int i=0; i<j; i++) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);

		edges[node1].push_back(node2);
		edges[node2].push_back(node1);
	}

	q.push(A);
	dist[A] = 0;
	pushed[A] = true;
	previous[A] = A;

	while (q.size()) {
		int current = q.front();
		q.pop();
		if (current == B) {
			break;
		}
		for (auto N:edges[current]) {
			if (pushed[N]) { continue; }
			previous[N] = current;
			dist[N] = dist[current] + 1;
			q.push(N);
			pushed[N] = true;
		}
	}

	int distance = dist[B];
	if (distance % 2 == 0) {
		int t = distance/2;
		findPath(B, distance);
		int m = paths[t];
		printf("%d %d\n", t, m);
	} else {
		printf("Broken heart\n");
	}
}

void findPath(int breadcrumb, int index) {
	if (previous[breadcrumb] == breadcrumb) {
		paths[index] = breadcrumb;
		return;
	}
	paths[index] = breadcrumb;
	findPath(previous[breadcrumb], index-1);
}

