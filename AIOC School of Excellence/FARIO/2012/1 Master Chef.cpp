#include <bits/stdc++.h>
using namespace std;

int N;
double ans, t;
double cumS[200005];

int main() {
	scanf("%d", &N);

	for (int i=1; i<=N; i++) {
		scanf("%lf", cumS+i);
		cumS[i] += cumS[i-1];
	}

	int lo = 1, hi = N;

	for (int i=1; i<=N; i++) {
		t += cumS[hi] - cumS[lo-1]; 
		ans += t/i;
		lo++; hi--;
	}

	ans *= 2;
	ans /= N;
	ans /= (N+1);

	printf("%d\n", (int)ans);
}
