#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f;

ll R, C;
ll box[1005][1005];
ll dp[1005][1005];

int main() {
    scanf("%lld %lld", &R, &C);

    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            scanf("%lld", &box[i][j]);
            box[i][j] = min(box[i][j], min(i==1 ? INF : box[i-1][j], j==1 ? INF : box[i][j-1]));
            
            if (i == 1 && j == 1)
                dp[i][j] = box[i][j];
            if (i > 1)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + box[i][j] * j);
            if (j > 1) 
                dp[i][j] = max(dp[i][j], dp[i][j-1] + box[i][j] * i);

        }
    }

    printf("%lld\n", dp[R][C]);
}
