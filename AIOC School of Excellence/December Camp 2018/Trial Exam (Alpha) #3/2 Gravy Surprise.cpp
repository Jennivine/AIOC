#include <bits/stdc++.h>
using namespace std;

int N,K; // length of chocolate bar & number of people in team
int chocolate[1000005];
int sum;

int decision (int x);

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

	int lo = 0; //minimum tastiness will always be >= to 1
	int hi = 1e9; //minimum tastiness cannot be larger than mean+1
	int mid = (lo+hi)/2;


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

	printf("%d\n", lo-1);

}

int decision (int x) {
	//returns 1 if minimum tastiness can be >= x, zero otherwise
	int buffer = 0;
	int index = 0;
	int ans = 0;

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
