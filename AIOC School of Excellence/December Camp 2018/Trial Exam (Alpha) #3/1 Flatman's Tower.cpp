#include <bits/stdc++.h>
using namespace std;

int N,H;
pair<int, int> blocks[1005];

int dp(int index, int currH);

int checked[1005][10005];
int value[1005][10005];

int main() {
	scanf("%d %d", &N, &H);

	for (int i=0; i<N; i++) {
		int w, h;
		scanf("%d %d", &w, &h);
		blocks[i] = make_pair(w,h);
	}

	int ans = dp(0,0);
	printf("%d\n",ans);

}

int dp(int index, int currH) {
	if (checked[index][currH]) { return value[index][currH]; } 
	if (currH > H) { return -1; }
	if (index == N) { return currH; }

	checked[index][currH] = 1;
	value[index][currH] = max(dp(index+1, currH), 
						  max(dp(index+1, currH+blocks[index].first),
							  dp(index+1, currH+blocks[index].second)));
	return value[index][currH];
}	
