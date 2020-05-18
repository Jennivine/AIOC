#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1<<8;

int R,C;

long long cityGrid[255][255];
long long dpState[255][255];

pair<int, int> breadcrumbs[255][255];

void printGrid();
void findBestPath();
void cleanPath(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			int prettiness;
			cin >> prettiness;

			cityGrid[i][j] = prettiness;
		}
	}

	// subtask 1: always optimal to film the same video twice
	findBestPath();
	long long ans = dpState[R-1][C-1];
	cout << ans << "\n";
	
	// subtask 2: after finding the optimal path, set score to zero & find optimal path again?
	cleanPath(R-1, C-1);
	printGrid();
	
	findBestPath();
	ans += dpState[R-1][C-1];

	cout << ans << "\n";
	cleanPath(R-1, C-1);
	printGrid();
}

void findBestPath() {
	
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			pair<int, int> breadcrumb;

			if (i == 0 && j == 0) {
				dpState[i][j] = cityGrid[i][j];
				breadcrumb = make_pair(i,j);

			} else if (i == 0) {
				dpState[i][j] = cityGrid[i][j] + dpState[i][j-1];
				breadcrumb = make_pair(i,j-1);

			} else if (j == 0) {
				dpState[i][j] = cityGrid[i][j] + dpState[i-1][j];
				breadcrumb = make_pair(i-1,j);

			} else {
				dpState[i][j] = cityGrid[i][j] + max(dpState[i][j-1], dpState[i-1][j]);
				
				if (dpState[i][j-1] >= dpState[i-1][j]) {
					breadcrumb = make_pair(i,j-1);
				} else {
					breadcrumb = make_pair(i-1,j);
				}
			}
			breadcrumbs[i][j] = breadcrumb;
		}
	}
}

void cleanPath(int r, int c) {
	pair<int, int> currCoord = make_pair(r,c);
	cityGrid[r][c] = 0;

	if (breadcrumbs[r][c] == currCoord) {
		return;
	} else {
		cleanPath(breadcrumbs[r][c].first, breadcrumbs[r][c].second);
	}
}
	
void printGrid() {
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cout << cityGrid[i][j] << " ";
		}
		cout << "\n";
	}
}
