#include <bits/stdc++.h>
using namespace std;

int hoops[100005];
int maxH = 505;
int totalHoops;

int cache[505][100005];
bool checked[505][100005];

int dp(int currH, int pos);

int main() {
	freopen("budgin.txt", "r", stdin);
	freopen("budgout.txt","w",stdout);

	int input;
	scanf("%d", &input);

	while (input != -1) {
		hoops[totalHoops] = input;
		totalHoops++;
		scanf("%d", &input);
	}

	

	int ans = dp(maxH, 0);
	printf("%d\n", ans);
}

