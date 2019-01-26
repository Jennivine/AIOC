#include <bits/stdc++.h>
using namespace std;

int n,w;
int road[100005];
int currMax;

int main(){
	freopen("manin.txt", "r", stdin);
	freopen("manout.txt","w",stdout);

	scanf("%d %d", &n, &w);

	for (int i=0; i<n; i++) {
		int people;
		scanf("%d", &people);
		road[i] = people;
		if (i < w) { 
			// initialise sliding window
			currMax+=people; 
		}
	}
	
	int slidingWindow = currMax;

	for (int i=w; i<n; i++) {
		slidingWindow = slidingWindow+road[i]-road[i-w];
		currMax = max(currMax, slidingWindow);
	}

	printf("%d\n", currMax);
}


