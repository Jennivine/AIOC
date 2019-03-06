#include <bits/stdc++.h>
using namespace std;

int R, C;
int square[1505][1505];
int maxSum[1505][1505];

int main() {
    scanf("%d %d", &R, &C);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            int value;
            scanf("%d", &value);
            square[i][j] = value;
            if (i == 0 && j == 0) {
                maxSum[i][j] = value;
            } else if (i == 0) {
                maxSum[i][j] = max(maxSum[i][j-1], maxSum[i][j-1] + value);
            } else if (j == 0) {
                maxSum[i][j] = max(maxSum[i-1][j], maxSum[i-1][j] + value);
            } else if (i == R-1 && j == C-1) {
                maxSum[i][j] = max(maxSum[i][j-1], maxSum[i-1][j]) + value;
            } else  {
                maxSum[i][j] = max(max(maxSum[i][j-1], maxSum[i-1][j]), 
                                   max(maxSum[i][j-1], maxSum[i-1][j]) + value);
            }
        }
    }

    printf("%d\n", maxSum[R-1][C-1]);
}




