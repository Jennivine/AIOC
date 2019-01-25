#include <bits/stdc++.h>
using namespace std;

int digits;
int ans;
int number[100005];

int main(){
	freopen("cutein.txt", "r",stdin);
	freopen("cuteout.txt","w",stdout);

	scanf("%d", &digits);

	for (int i=0; i<digits; i++) {
		int d;
		scanf("%d",&d);
		number[i] = d;
	}

	int index = digits-1;
	while (number[index] == 0){
		ans++;
		index--;
	}

	printf("%d\n", ans);
}

