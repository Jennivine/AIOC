#include <bits/stdc++.h>
using namespace std;

int x,y;
int number (int x, int y);

int main() {
//    freopen("chimpin.txt", "r", stdin);
//    freopen("chimpout.txt","w",stdout);

    scanf("%d %d", &x, &y);
    printf("%d\n", number(x,y));    
}

int number(int x, int y) {
    int ans;
    int u = x+y, v = x-y;

    if (u>0) {
        if (v >= 0) {
            x <<= 1;
            ans = x*(x-1) + v;
        } else {
            y <<= 1;
            ans = y*(y-1) + v;
        }
    } else {
        if (v < 0) {
            x <<= 1;
            ans = -x*(1-x) - v;
        } else {
            y <<=1;
            ans = -y*(1-y) - v;
        }
    }

    return ans;
}

