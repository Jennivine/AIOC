#include <bits/stdc++.h>
using namespace std;

int lollies;

int main() {
    freopen("hallin.txt", "r", stdin);
    freopen("hallout.txt","w",stdout);

    scanf("%d", &lollies);

    int children = 0;
    int sum = 0;

    while (sum <= lollies) {
        children++;
        sum += children;
    }

    printf("%d\n", children);
}
