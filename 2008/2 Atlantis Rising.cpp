#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> myStack;
int cities[1000005];
int ans;

int main() {
	freopen("atlanin.txt", "r", stdin);
	freopen("atlanout.txt","w",stdout);

	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", cities+i);
	}

	for (int i=0; i<N; i++) {
		int city = cities[i];
		while (! myStack.empty()){
			if (city <= myStack.top()) {
				break;
			} else {
				ans++;
				printf("%d ", i+1);
				myStack.pop();
			}
		}
		myStack.push(city);
	}

	printf("%d\n", ans);
}
