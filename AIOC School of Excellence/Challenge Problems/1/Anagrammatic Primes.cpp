#include <bits/stdc++.h>
using namespace std;
int arr[22] = {2, 3, 5, 7, 11, 13, \
              17, 31, 37, 71, 73, \
              79, 97, 113, 131, 199, \
              311, 337, 373, 733, 919, 991};

int main () {
  freopen("primes.in","r",stdin);
  freopen("primes.out","w",stdout);

  int N;
  int i = 0;
  scanf("%d", &N);

  if (N>1000) {
    printf("0\n");
  } else {
    while (i<22) {
      if (arr[i] > N){
        printf("%d\n",arr[i]);
        break;
      }
      i++;
    }
  }
}
