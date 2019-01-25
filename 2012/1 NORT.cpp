#include <bits/stdc++.h>
using namespace std;

int W,H;

int main() {
	freopen("nortin.txt","r",stdin);
	freopen("nortout.txt","w",stdout);

	scanf("%d %d", &W, &H);

	int ans = W*H;

	if (ans % 2 == 1) { ans--; }

	printf("%d\n", ans);
}
