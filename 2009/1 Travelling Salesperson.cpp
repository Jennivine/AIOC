#include <bits/stdc++.h>
using namespace std;

int X,Y,Z;

int main() {
	freopen("salesin.txt","r",stdin);
	freopen("salesout.txt","w",stdout);

	scanf("%d", &X);
	scanf("%d", &Y);
	scanf("%d", &Z);

	printf("%d\n", X+Y+Z-min(min(X,Y),Z));
}




