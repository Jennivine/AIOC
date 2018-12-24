#include <bits/stdc++.h>
using namespace std;

int x_co[100005];
int y_co[100005];

int main() {
  freopen("spiesin.txt","r",stdin);
  freopen("spiesout.txt","w",stdout);

  int N;
  scanf("%d",&N);

  for (int i=0; i<N; i++){
    int x,y;
    scanf("%d %d", &x, &y);
    x_co[i] = x;
    y_co[i] = y;
  }

  sort(x_co, x_co+N);
  sort(y_co, y_co+N);

  int median = N/2;

  printf("%d %d\n", x_co[median], y_co[median]);
}
