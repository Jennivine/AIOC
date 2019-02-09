#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bugsin.txt", "r", stdin);
    freopen("bugsout.txt","w",stdout);

    int currYear;
    scanf("%d", &currYear);

    printf("%d", (currYear/7+1)*7);

}
