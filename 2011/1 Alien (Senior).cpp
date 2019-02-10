#include <bits/stdc++.h>
using namespace std;

int N, W;
int human[100005];

int main() {
    freopen("alienin.txt", "r", stdin);
    freopen("alienout.txt","w",stdout);

    scanf("%d %d", &N, &W);
    for (int i=0; i<N; i++) {
        scanf("%d", human+i);
    }

    int ans = 0, first = 0;

    for (int last=0; last<N; last++) {
        while (human[last] - human[first] >= W) {
            first++;
        } 
        if (ans < last-first+1) {
            ans = last-first+1;
        }
    }

    printf("%d\n", ans);
}
