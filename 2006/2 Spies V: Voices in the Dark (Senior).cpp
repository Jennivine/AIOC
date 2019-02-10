#include <bits/stdc++.h>
using namespace std;

int j, g, ans;
pair<int, int> JeanDavid[1000005];
pair<int, int> Geoffrey[1000005];

int main() {
	freopen("spiesin.txt", "r", stdin);
	freopen("spiesout.txt","w",stdout);

	scanf("%d", &j);
	for (int i=0; i<j; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		JeanDavid[i] = make_pair(start, end);
	}

	scanf("%d", &g);
	for (int i=0; i<g; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		Geoffrey[i] = make_pair(start, end);
	}
}
