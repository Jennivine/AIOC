#include <bits/stdc++.h>
using namespace std;

int n,k;
int photos[100005];
int a[100005];

int main() {
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", photos+i);
    }

    // full solution: largest contiguous sum of at most length k

    /* subtask 1:
    int ans = 0, s1 = 0;
    for (int i=0; i<n; i++) {
        if (i < k) {
            ans += photos[i];
            s1 = ans;
        } else {
            ans = ans-photos[i-k]+photos[i];
            if (ans > s1) {
                s1 = ans;
            }
        }
    }

    printf("%d\n", s1); */

    //subtask 2:
    a[0] = photos[0];
    int runMax = a[0];
    for (int i=1; i<n; i++) {
        a[i] = max(photos[i],  a[i-1]+photos[i]);
        if (a[i] > runMax) {
            runMax = a[i];
        }
    }
    printf("%d\n", runMax);
}

