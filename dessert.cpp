#include <bits/stdc++.h>
using namespace std;
int cake[1000005];
long long runSum;
long long s[1000005];
long long target;
long long ans;


int main(){
  freopen("nomin.txt","r", stdin);
  freopen("nomout.txt","w",stdout);
  int N;
  scanf("%d", &N);

  for (int i=0; i<N; i++){
    int c;
    scanf("%d", &c);
    cake[i] = c;
    runSum += c;
    s[i] = runSum;
  }

  for (int i=0; i<=N; i++){
    long long S = s[i];
    target = 2*S;

    int lo = 0;
    int hi = N;
    while (lo != hi){
      int mid = (lo+hi)/2;
      if (s[mid] < target){
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
     if (s[lo] == target){
       ans = max(ans,S);
     }
  }


  printf("%lld\n",ans);

}
