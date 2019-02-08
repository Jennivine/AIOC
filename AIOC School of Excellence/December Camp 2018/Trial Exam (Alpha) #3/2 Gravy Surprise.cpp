#include <bits/stdc++.h>
using namespace std;

int N,K; // length of chocolate bar & number of people in team
int chocolate[1000005];
long long sum;

int decision (long long x); // returns 0 or 1

int main() {
	freopen("choc.in","r",stdin);
	freopen("choc.out","w",stdout);

	scanf("%d %d", &N, &K);

	for (int i=0; i<N; i++) {
		int tastiness;
		scanf("%d", &tastiness);
		chocolate[i] = tastiness;
		sum += tastiness;
	}

	long long lo = 0; //minimum tastiness will always be >= to 1
	long long hi = 1e11+1; //minimum tastiness cannot be larger than mean+1
	long long mid = (lo+hi)/2;

	//int ans = decision(15);
	//printf("%d\n", ans);

	while (lo != hi) {
        mid = (lo+hi)/2;
		//printf("lo:%d hi:%d mid:%d\n", lo, hi, mid);

		if (!decision(mid)) {
            hi = mid;
		} else {
			lo = mid+1;
		}
	}

	printf("%lld\n", lo-1);

}

int decision (long long x) {
	//returns 1 if minimum tastiness can be >= x, zero otherwise
	long long buffer = 0;
	long long index = 0;
	long long ans = 0;

	while (index < N) {
		buffer += chocolate[index];
		//printf("%d\n", buffer);
		if (buffer >= x) {
			ans++;
			buffer = 0;
		}
		index++;
	}

	//printf("%d\n",ans);
	if (ans >= K) {
		return 1;
	} else {
		return 0;
	}
}
