#include <bits/stdc++.h>
using namespace std;
int ans;
int spaceLeft;
int cache[10000005];
int isDone[10000005];

int possibleWays(int n);

int main(){
  freopen("life.in","r", stdin);
  freopen("life.out","w",stdout);
  scanf("%d", &spaceLeft);
  ans = possibleWays(spaceLeft);
  printf("%d\n", ans);
}

int possibleWays(int n){
  if (isDone[n]) {
    return cache[n];
  }
  if (n == 0){
    return 1;
  } else if (n < 0) {
    return 0;
  } else {
    isDone[n] = 1;
    int total = (possibleWays(n-3) +
                 possibleWays(n-5) +
                 possibleWays(n-8)) % 31337;
    cache[n] = total;
    return cache[n];
  }
}
