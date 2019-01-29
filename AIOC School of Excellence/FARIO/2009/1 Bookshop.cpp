#include <bits/stdc++.h>
using namespace std;

int N, K;
int books[100005];
int myBooks[100005];
int idx;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", books+i);
	}

	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		int width;
		scanf("%d", &width);

		while (true) {
			if (books[idx++] == width) { break; }
		}

		printf("%d\n", idx);
	}
}
