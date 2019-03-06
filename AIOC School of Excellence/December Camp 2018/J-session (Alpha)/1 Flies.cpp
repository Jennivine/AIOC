#include <bits/stdc++.h>
using namespace std;

int V, E;
vector <int> graph[105];
int previous[105], pushed[105], dist[105];
queue <int> q;
vector <int> path, newPath;

void findPath (int breadcrumb);
void findSecondPath (int breadcrumb);

int BFS (int start, int end);

int main() {
	freopen("fliesin.txt", "r", stdin);
	freopen("fliesout.txt","w",stdout);
	
	scanf("%d", &V);
	scanf("%d", &E);

	for (int i=0; i<E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int minD = BFS(1, V); int ans = 1e9;

	// breadcrumb to find that path
	findPath(V);
 
	for (int i=0; i<path.size()-1; i++) {
		while (q.size()) { q.pop(); }
		for (int i=0; i<105; i++) { pushed[i] = 0; }

		//remove edge from graph
		int a = path[i], b = path[i+1];
		graph[a].erase(remove(graph[a].begin(), graph[a].end(), b));
		graph[b].erase(remove(graph[b].begin(), graph[b].end(), a));

		int d = BFS(1, V);
		if (d < ans) {
			ans = d;
			findSecondPath(V);
		}

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	printf("%d\n", ans);
	for (auto edges:newPath) {
		printf("%d ", edges);
	}
	printf("\n");
}

void findPath(int breadcrumb) {
	if (previous[breadcrumb] == breadcrumb) {
		path.push_back(breadcrumb);
		return;
	}

	findPath(previous[breadcrumb]);
	path.push_back(breadcrumb);
}

void findSecondPath(int breadcrumb) {
	if (previous[breadcrumb] == breadcrumb) {
		newPath.push_back(breadcrumb);
		return;
	}
	findSecondPath(previous[breadcrumb]);
	newPath.push_back(breadcrumb);
}

int BFS(int start, int end) {
	// BFS shortest path from 1 to N
	q.push(start);
	previous[start] = start;
	pushed[start] = 1;
	dist[start] = 0;

	while (q.size()) {
		int current = q.front();
		q.pop();
		if (current == end) {
			break;
		} 
		for (auto n:graph[current]) {
			if (pushed[n]) { continue; }
			previous[n] = current;
			dist[n] = dist[current] + 1;
			q.push(n);
			pushed[n] = 1;
		}
	}

	return dist[end];
}
