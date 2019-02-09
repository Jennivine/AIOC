#include <bits/stdc++.h>
using namespace std;

int quadrants[4];
int N, M;

int main() {
   freopen("flowin.txt", "r", stdin);
   freopen("flowout.txt","w",stdout);

   scanf("%d %d", &N, &M);

   for (int i=0; i<M; i++) {
       int x, y;
       scanf("%d %d", &x, &y);

       if (x <= N && y <= N) {
           // Quadrant 1
           quadrants[0] += 1;
       } else if (y <= N) {
           // Quandrant 2
           quadrants[1] += 1;
       } else if (x <= N) {
           // Quandrant 3
           quadrants[2] += 1;
       } else {
           // Quandrant 4
           quadrants[3] += 1;
       }
   }

   int ans = 0;
   for (int i=0; i<4; i++) {
       if (quadrants[i] > quadrants[ans]) {
           ans = i;
       }
   }

   printf("%d %d\n", ans+1, quadrants[ans]);
}
