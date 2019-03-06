#include <bits/stdc++.h>
using namespace std;

int n,k;
int photos[100005];
int prefix[100005];
//deque<int> myDq;

int dp(int arr[], int n, int k);

int main() {
    scanf("%d %d", &n, &k);
    for (int i=1; i<=n; i++) {
        scanf("%d", photos+i);
    }

    // full solution: largest contiguous sum of at most length k
    for (int i=1; i<=n; i++) {
        prefix[i] = prefix[i-1] + photos[i];
    }
	
	// find indices q and w such that w < q, q-w <= k, 
	// and prefix[q] - prefix[w] is the maximum possible
	int ans = -1e9;
	for (int i=1; i<=k; i++) {
		//printf("%d %d\n", i, dp(photos, n, i));
		ans = max(ans, dp(photos, n, i));
	}
	
	printf("%d\n", ans);
}

// Returns maximum sum in a subarray of size k. 
int dp(int arr[], int n, int k)  {   
    int res = 0;
	for (int i=0; i<k; i++) 
       res += arr[i]; 
  
  
    int curr_sum = res; 
    for (int i=k; i<n; i++) { 
       curr_sum += arr[i] - arr[i-k]; 
       res = max(res, curr_sum);
	   //printf("%d %d\n", i, curr_sum);
    } 
  
    return res; 
} 