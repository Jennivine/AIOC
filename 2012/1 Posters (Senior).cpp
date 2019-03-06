#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair <int, int> topLeftP;

int main() {
    freopen("postin.txt", "r", stdin);
    freopen("postout.txt","w",stdout);

    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (i == 1) {
            topLeftP = make_pair(x,x+y);
        } else {
            if (x < topLeftP.second) {
                //printf("curr x: %d, curr y: %d, poster: %d\n", topLeftP.first, topLeftP.second, i);
                ans = i;
                topLeftP = make_pair(x, x+y);
            }
        }
    }

    printf("%d\n", ans);
}
