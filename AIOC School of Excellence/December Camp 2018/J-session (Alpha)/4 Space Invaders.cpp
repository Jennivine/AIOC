#include <bits/stdc++.h>
using namespace std;

int totalBlocked;
pair <int, int> spaceships[100005];

int main(){
  freopen("spacein.txt","r",stdin);
  freopen("spaceout.txt","w",stdout);

  int w, h;
  scanf("%d %d", &w, &h);

  int num; //number of spaceships
  scanf("%d", &num);

  for (int i=0; i<num; i++){
    int vertices;
    scanf("%d", &vertices);
    int minX, maxX; 
    for (int j=0; j<vertices;j++){
      int x, y;
      scanf("%d %d", &x, &y);
      if (j==0) {
        // initialise the values
        minX = x;
        maxX = x;
      } else {
        if (x < minX){
          minX = x;
        } else if (x > maxX) {
          maxX = x;
        }
      }
    }
    spaceships[i] = make_pair(minX, maxX);
  }

  sort(spaceships, spaceships+num);

  int rangeL = spaceships[0].first;
  int rangeR = spaceships[0].second;

  for (int i=1; i<num; i++){
    int l = spaceships[i].first;
    int r = spaceships[i].second;

    if (l > rangeR) {
      //starting new range
      totalBlocked += rangeR - rangeL;
      rangeL = l;
      rangeR = r;
    } else if (rangeR < r){
      //extend existing range
      rangeR = r;
    } 
  }

  totalBlocked += rangeR - rangeL;

  printf("%d", w-totalBlocked);
}


