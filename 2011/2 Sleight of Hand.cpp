#include <bits/stdc++.h>
using namespace std;

int N, S, K;
int cups[1000005];

int main(){
	freopen("handin.txt","r",stdin);
	freopen("handout.txt","w",stdout);

	scanf("%d %d %d", &N, &S, &K);
	cups[S] = 1; //you only need to keep track of how S changes

	for (int i=0; i<K; i++){
		int a,b;
		scanf("%d %d", &a, &b);

		if (a == S) { S = b; continue; }
		if (a < S && b >= S) { S--; } 
		if (a > S && b <= S) { S++; }
	}

	printf("%d\n", S);
}
