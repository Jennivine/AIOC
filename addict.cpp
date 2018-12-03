#include <bits/stdc++.h>
using namespace std;

int items[1200];
int cache[1005];

int main(){
  freopen("addict.in","r", stdin);
  freopen("addict.out","w",stdout);

  int x,y;
  scanf("%d %d", &x, &y);

  int index = 0;
  for (int i=0; i<48; i++){
    for (int j=0; j<=i;j++){
      items[index] = i;
      index++;
    }
  }

  for (int i=x-1; i<y; i++){
    cache[i] = cache[i-1] + items[i];
  }

  printf("%d\n", cache[y-1]);


}
