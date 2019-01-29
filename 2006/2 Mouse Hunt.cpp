#include <bits/stdc++.h>
using namespace std;

map <int, int> x_co;
map <int, int> y_co;

//(up,down)=y_coordinates; (right,left)=x_coordinates
int u = 0;
int d = 1e9;
int r = 0;
int l = 1e9;

int main() {
	freopen("mousein.txt", "r", stdin);
	freopen("mouseout.txt","w",stdout);

	for (int i=0; i<8; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x_co[x]++;
		y_co[y]++;

		if (x < l) {l=x;} else if (x > r) {r=x;}
		if (y < d) {d=y;} else if (y > u) {u=y;}
	}

	for (auto i:x_co) {
		if (x_co[i.first] == 4) {
			if (i.first == l) {
				printf("W\n");
			} else if (i.first == r) {
				printf("E\n");
			}
		}
	}

	for (auto i:y_co) {
		if (y_co[i.first] == 4) {
			if (i.first == u) {
				printf("N\n");
			} else if (i.first == d) {
				printf("S\n");
			}
		}
	}

}




