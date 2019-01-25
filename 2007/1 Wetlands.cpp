#include <bits/stdc++.h>
using namespace std;

int dam;
int rainfall[8];

int main() {
	freopen("wetin.txt", "r", stdin);
	freopen("wetout.txt","w",stdout);

	for (int i=0; i<8; i++){
		int rain;
		scanf("%d", &rain);

		dam += rain - 10;
		dam = max(dam, 0);
	}

	printf("%d\n", dam);
}
