#include <bits/stdc++.h>
using namespace std;

int d, ans;
int ants[100005];
stack<int> S;

int main() {
	freopen("antsin.txt", "r", stdin);
	freopen("antsout.txt","w",stdout);

	scanf("%d", &d);
	for (int i=0; i<d; i++) {
		scanf("%d", ants+i);
	}

	for (int i=0; i<d; i++) {
		if (S.empty() || ants[i] > S.top()) {
			S.push(ants[i]);
		} else {
			int buffer = 0;
			while (! S.empty()) {
				S.pop();
				buffer++;
			}
			if (buffer >= 2) {
				ans++;
			}
			S.push(ants[i]);
		}
	}

	if (S.size() >= 2) {
		ans++;
	}

	printf("%d\n", ans);
}

