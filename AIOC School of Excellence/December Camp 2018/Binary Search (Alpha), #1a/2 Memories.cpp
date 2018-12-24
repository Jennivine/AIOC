#include <bits/stdc++.h>
using namespace std;

int N, R, C;

long arr[1000005];
long slideSum[1000005];

int decision(int x);

int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d %d %d", &N, &R, &C);
    //printf("%d %d %d\n", N, R, C);


    for (int i=0; i<N; i++) {
	long height;
	scanf("%ld", &height);
	arr[i] = height;
    }

    sort(arr, arr+N);

    for (int i=0; i<=N-C; i++) {
	slideSum[i] = arr[i+C-1] - arr[i];
	//printf("%lld\n",slideSum[i]);
    }

    int hi = 1e9;
    int lo = 0;

    while (lo < hi) {
	//printf("low:%d high:%d mid:%d\n", lo, hi, mid);
	int mid = (hi+lo)/2;
	if (decision(mid)) {
	    hi = mid;
	} else {
	    lo = mid + 1;
	}
    }
    printf("%d\n", lo);

}

int decision(int x) {
    int i = 0;
    int ans = 0;
    while (i <= N-C) {
	if (slideSum[i] <= x){
	    ans++;
	    if (ans == R) {
		return 1;
	    }
	    i += C;
	} else {
	    i++;
	}
    }
    return 0;
}
