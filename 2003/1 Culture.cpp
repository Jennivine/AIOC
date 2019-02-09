#include <bits/stdc++.h>
using namespace std;

int bacterium;

int main() {
    freopen("cultin.txt", "r", stdin);
    freopen("cultout.txt","w",stdout);
    
    scanf("%d", &bacterium);

    int ans = 0;
    while (bacterium%2 == 0) {
        bacterium /= 2;
        ans++;
    }

    printf("%d %d\n", bacterium, ans);
}
