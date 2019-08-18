#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long bigint;

bigint n,k,s;

bigint josephus (bigint n, bigint k, bigint s) {
	bigint i = s+1;
	
	for (bigint x = i; x <= n; x++, i++) {
		s = (s+k) % i;
	}

	return s;
}

int main () {
	freopen("teamin.txt", "r", stdin);
	freopen("teamout.txt","w",stdout);

	scanf("%llu %llu", &n, &k);
	s = 4;

	for (bigint x=s; x>0; x--) {
		printf("%llu ",josephus(n,k,x-1)+1);
	}

	cout << "\n";
}
