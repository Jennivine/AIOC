#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int R = 1e2+5;

int r,l;
char str[N], c;
char mat[R][N];

int main() {
    freopen("zigin.txt", "r", stdin);
    freopen("zigout.txt","w",stdout);

    scanf("%d", &r);
    do {
        c = getchar();
        if (isupper(c)) { 
            str[++l] = c; 
        }
    } while (c != '#');

    int cRow = 1, cCol = 1, direction = -1;
    for (int i=1; i<=l; i++) {
        mat[cRow][cCol++] = '.'; // will put letter in this space
        if (cRow == 1 || cRow == r) {
            direction *= -1; // reverse direction
        }
        cRow += direction;
    }

    int wordIdx = 0;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=l; j++) {
            if (mat[i][j] == '.'){
                mat[i][j] = str[++wordIdx];
            }
        }
    }

    // go through matrix again, this time outputting the deciphered message
    cRow = 1, cCol = 1, direction = -1;
    for (int i=1; i<=l; i++) {
        putchar(mat[cRow][cCol++]);
        if (cRow == 1 || cRow == r) {
            direction *= -1;
        }
        cRow += direction;
    }
    return 0;
}
