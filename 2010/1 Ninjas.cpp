#include <bits/stdc++.h>
using namespace std;

int N,K;

int main() {
	freopen("ninjain.txt","r",stdin);
	freopen("ninjaout.txt","w",stdout);
	
	scanf("%d %d", &N, &K);
	
	int remainder = N%(K+1);
	int howMany = (N-remainder)/(K+1);
	int ans = howMany*K + max(0,remainder-1);

	printf("%d\n", ans);
}
