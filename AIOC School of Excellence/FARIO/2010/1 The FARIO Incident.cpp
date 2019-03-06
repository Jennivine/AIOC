#include <bits/stdc++.h>
using namespace std;

#define MOD 1000003

string key[15] = {"0","24","135","26","157","2468","359","48","579","68"};

int N, D, ans;
int DP[2][15];

int main() {
	scanf("%d %d", &N, &D);
	int cur = 0, pre = 1;


	DP[0][D] = 1;
	for (int i=0; i<N-1; i++) {
		pre = cur;
		cur = !cur;
		for (int j=1; j<=9; j++) {
			DP[cur][j] = 0;
			for (int k=0; k<key[j].size(); k++) {
				DP[cur][j] = ( DP[cur][j] + DP[pre][key[j][k] - '0'] ) % MOD;
			}
		}
	}

	for (int i=1; i<=9; i++) {
		ans += DP[cur][i];
	}

	printf("%d\n" , ans % MOD );
}
