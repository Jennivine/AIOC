#include <bits/stdc++.h>
using namespace std;
int N;
int arr[50005];
int seenB[50005][5];
int cache[50005][5];
int cSum[50005];
int slideLen;
int ans;

int maxCapacity (int start, int num);

int main() {
    freopen("trainin.txt", "r", stdin);
    freopen("trainout.txt", "w", stdout);
    scanf("%d", &N);
    
    for (int i=0; i<N; i++) {
        int l;
        scanf("%d", &l);
        arr[i] = l;
    }
    
    scanf("%d", &slideLen);
    
    cSum[0] = 0;
    //printf("%d\n", cSum[0]);
    
    for (int i=1; i<=N; i++) {
        cSum[i] = cSum[i-1] + arr[i-1];
        //printf("%d\n", cSum[i]);
    }
    
    if (slideLen*3 >= N) {
        printf("%d\n", cSum[N]);
    } else {
        for (int i=0; i<N; i++){
            ans = max(ans,maxCapacity(i,0));
        }
        printf("%d\n", ans);
    }
    
}

// returns the max result given i as a starting point of the
// three engines
int maxCapacity (int start, int num) {
    if (start > N) { return -1000000000; }
    if (num == 3) { return 0; }
    
    if (seenB[start][num]) {
        return cache[start][num];
    }
    
    seenB[start][num] = 1;
    int currV = cSum[start+slideLen] - cSum[start];
    int answer = max(maxCapacity(start+slideLen,num+1) + currV,
                     maxCapacity(start+1,num));
    cache[start][num] = answer;
    //printf("start = %d num = %d answer = %d\n", start, num, answer);
    return answer;
}
