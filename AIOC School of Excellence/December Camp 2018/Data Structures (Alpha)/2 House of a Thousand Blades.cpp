#include <bits/stdc++.h>
using namespace std;

int W,H; //Width and height of the board
int x, p;
int ans;

int main() {
	scanf("%d %d", &W, &H);

	vector<int> Top = {H};

	for (int i=0; i<W; i++){
		int x;
		scanf("%d", &x);
		ans += i && x != p;
		while (Top.back() < x) {
			Top.pop_back();
		}
		ans += x < Top.back();
		Top.push_back(x);
		p = x;
	}

	vector<int> Bot = {0};
	p = -1;

	for (int i=0; i<W; i++){
		int x;
		scanf("%d", &x);
		ans += i && x != p;
		while (Bot.back() > x){
			Bot.pop_back();
		}
		ans += x > Bot.back();
		Bot.push_back(x);
		p = x;
	}

	printf("%d\n", ans);
}
