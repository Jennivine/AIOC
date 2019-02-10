#include <bits/stdc++.h>
using namespace std;

int n;

int seq(int n);

int main() {
    freopen("hailin.txt", "r", stdin);
    freopen("hailout.txt","w",stdout);

    scanf("%d", &n);
    while (n != 0) {
        printf("%d\n", seq(n));
        scanf("%d", &n);
    }
}

int seq(int n) {
    int ans = 0;
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3*n + 1;
        } else {
            n /= 2;
        }
        ans++;
    }
    return ans;
}

