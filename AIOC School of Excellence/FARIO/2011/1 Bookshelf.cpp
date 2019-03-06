#include <bits/stdc++.h>
using namespace std;

int N, M, I;
int bookshelf[100005];
bool affected[100005];

int main() {
    int ans = 0;

    scanf("%d %d %d", &N, &M, &I);
    for (int i=1; i<=N; i++) {
        scanf("%d", bookshelf+i);
    }

    for (int i=1; i<=M; i++) {
        int a; // affected book
        scanf("%d", &a);
        affected[a] = true;
        int start = a;
        while (bookshelf[start-1] >= bookshelf[start] && !affected[start-1]) {
            affected[--start] = true;
        }
        start = a;
        while (bookshelf[start+1] >= bookshelf[start] && !affected[start+1]) {
            affected[++start] = true;
        }
    }

    for (int i=1; i<=I; i++) {
        int oldBook;
        scanf("%d", &oldBook);
        ans += affected[oldBook];
    }

    printf("%d\n", ans);
}
