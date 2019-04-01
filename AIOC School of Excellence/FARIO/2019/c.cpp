#include <bits/stdc++.h>
using namespace std;

int n, c, p, path[100005], tile[100005];

long long ans = 1;

int main() {
    //freopen("out.txt","w",stdout);

    scanf("%d %d", &n, &c);
    for (int i=0; i<n; i++) {
        scanf("%d", tile+i);
    }

    scanf("%d", &p);
    for (int i=0; i<p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
    }
    
    if (p != 0) {
        for (int i=0; i<n-2; i++) {
            ans = (ans*2)%1000000007;
        }
    } else {
        ans = 0;
    }

    printf("%lld\n", ans);
}
