#include <bits/stdc++.h>
using namespace std;

int S;
int stacks[100005];

int main(){
	freopen("balancein.txt", "r", stdin);
	freopen("balanceout.txt","w",stdout);

	scanf("%d", &S);
	for (int i=0; i<S; i++) {
		scanf("%d", stacks+i);
	}

	int moves = 0;
	int l_Idx = 0;
	int r_Idx = S-1;

	while (l_Idx < r_Idx) {
		if (stacks[l_Idx] > stacks[r_Idx]) {
			stacks[r_Idx-1] += stacks[r_Idx];
			stacks[r_Idx] = 0; // reset just to be clean
			moves++;
			r_Idx--;
		} else if (stacks[l_Idx] < stacks[r_Idx]) {
			stacks[l_Idx+1] += stacks[l_Idx];
			stacks[l_Idx] = 0; // reset just to be clean
			moves++;
			l_Idx++;
		} else {
			r_Idx--;
			l_Idx++;
		}
	}

	printf("%d\n", moves);
}
