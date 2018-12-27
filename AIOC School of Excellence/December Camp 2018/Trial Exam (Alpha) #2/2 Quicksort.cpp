#include <bits/stdc++.h>
using namespace std;
vector<int> connection[10005];

int N;
int a,b;

void hasPath(int x);
int noCall;
int checked[10005];

int main () {
	freopen("qsortin.txt", "r", stdin);
	freopen("qsortout.txt", "w", stdout);

	scanf("%d", &N);
	
	//directed graph: reading input and storing in adjacency list
	for (int i=1; i<=N; i++) {
		int instruction;
		scanf("%d", &instruction);
		if (instruction == 1) {
			connection[i].push_back(i+1);
		} else if (instruction == 2) {
			scanf("%d", &a);
			connection[i].push_back(a);
		} else {
			scanf("%d %d", &a, &b);
			connection[i].push_back(a);
			connection[i].push_back(b);
		}
	}
	
	hasPath(1); //floodfill from the first node

	for (int i=1; i<=N; i++) {
		if (!checked[i]) {noCall++;}
	}

	printf("%d\n", noCall);
}

void hasPath (int x){
	if (checked[x]) {
		return;
	}
	checked[x] = 1;
	for (auto i:connection[x]) {
		hasPath(i);
	}
}
