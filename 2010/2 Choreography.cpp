#include <bits/stdc++.h>
using namespace std;

int D,T;
int dancers[100005];
int hulaHoops;

int main() {
	freopen("dancein.txt","r",stdin);
	freopen("danceout.txt","w",stdout);

	scanf("%d %d", &D, &T);

	for (int i=0; i<T; i++) {
		int a,b;
		scanf("%d %d", &a, &b);

		if (dancers[a] == 0){ hulaHoops++; dancers[a]++; }
		dancers[a]--;
		dancers[b]++;
	}

	printf("%d\n", hulaHoops);
}
