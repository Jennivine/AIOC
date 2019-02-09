#include <bits/stdc++.h>
using namespace std;

int ans;
char c;

int main() {
    freopen("acadin.txt", "r", stdin);
    freopen("acadout.txt","w",stdout);

    do {
        c = getchar();
        if (c == 'i') { 
            ans++; 
        } else if (c == 'o') { 
            ans--; 
        }
    } while (c != 'x');

    printf("%d\n", ans);
}
