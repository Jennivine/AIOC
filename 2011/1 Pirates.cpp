#include <bits/stdc++.h>
using namespace std;

int L, X, Y;

int main() {
	freopen("piratein.txt", "r", stdin);
	freopen("pirateout.txt", "w", stdout);

	scanf("%d", &L);
	scanf("%d", &X);
	scanf("%d", &Y);

	int opt1 = X + Y;
	int opt2 = (L-X) + (L-Y);

	printf("%d\n", min(opt1, opt2));
}
