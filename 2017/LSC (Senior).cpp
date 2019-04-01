#include <bits/stdc++.h>
using namespace std;

int N, L;
int A[100005];
int shops[100005];

int main() {
    freopen("lscin.txt", "r", stdin);
    freopen("lscout.txt","w",stdout);

    scanf("%d %d", &N, &L);
    for (int i=1; i<=N; i++) {
        scanf("%d", A+i);
    }

    for (int i=1; i<=N; i++) {
        scanf("%d", shops+i);
    }
    
    int lo = 1, hi = L+1;

    for (int i=2; i<=N; i++) {
        int curPos = A[shops[i]];
        int prevPos = A[shops[i-1]];

        while (abs(prevPos - lo) > abs(curPos - lo)) {
            if (lo > hi) { lo = -1; break; }
            lo++;
        }

        while (abs(prevPos - hi) > abs(curPos - hi)) {
            if (lo > hi) { lo = -1; break; }
            hi--;
        }
    }

    printf("%d\n", lo);
}

