#include <bits/stdc++.h>
using namespace std;

int R, S, Rose[10005], Scarlet[10005];

int main() {
    freopen("snapin.txt", "r", stdin);
    freopen("snapout.txt","w",stdout);

    scanf("%d %d", &R, &S);
    for (int i=0; i<R; i++) {
        int card;
        scanf("%d", &card);
        Rose[card]++;
    }

    for (int i=0; i<S; i++) {
        int card;
        scanf("%d", &card);
        Scarlet[card]++;
    }

    int ans = 0;
    for (int i=1; i<=10000; i++) {
        ans += Rose[i]*Scarlet[i];
    }

    printf("%d\n", ans);
}
