#include <bits/stdc++.h>
using namespace std;

int a,b;
int cipher[100005];
int sequence[35];

int main() {
	freopen("safein.txt","r",stdin);
	freopen("safeout.txt","w",stdout);

	scanf("%d %d", &a, &b);

	for (int i=0; i<a; i++) {
		int code;
		scanf("%d", &code);
		cipher[i] = code;
	}

	for (int i=0; i<b; i++) {
		int snippet;
		scanf("%d", &snippet);
		sequence[i] = snippet;
	}

	//trying every combination.. eek
	int start = 0;
	int shift;
	while (true) {
		shift = cipher[start] - sequence[0];
		int i = 1;
		int wrongStart = false;
		while (i < b) {
			int currShift = cipher[start+i] - sequence[i];
			if (currShift != shift) {
				wrongStart = true;
				break;
			}
			i++;
		} 

		if (!wrongStart && shift >= 0) {
			break;
		}
		start++;
	}

	for (int i=0; i<a; i++) {
		printf("%d\n", cipher[i]-shift);
	}
}
