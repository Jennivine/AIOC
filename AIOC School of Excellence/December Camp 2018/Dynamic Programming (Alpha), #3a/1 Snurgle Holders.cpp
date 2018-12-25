#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> industry[100005]; //tree pointing to its children
int book[100005]; //keeps track of which step has an inspector
int ans;
int checked[100005];

int solve(int node);

int main() {
	freopen("snurgle.in", "r", stdin);
	freopen("snurgle.out", "w", stdout);
	
	scanf("%d", &n);

	for (int i=1; i<n; i++) {
		int node;
		scanf("%d", &node);
		industry[node].push_back(i);
	}

	int a = solve(n);
	for (int i=0; i<n; i++) {
		if (book[i]) {
			//printf("%d\n",i);
			ans++;
		}
	}

	printf("%d\n",ans);
}

int solve(int node) {
//	printf("%d\n",node);
	if (checked[node]) {return book[node];}
	if (industry[node].empty()){
		//base case: the leaves of the tree
		book[node] = 1;
		return 1;
	} 
	for (auto y:industry[node]){
		int color = solve(y);
		if (color == 1){
			book[node] = 0;
			checked[node]=1;
		}
	}
	if (!checked[node]){
		book[node] = 1;
		checked[node]=1;
		return 1;
	} else {
		return 0;
	}
}

