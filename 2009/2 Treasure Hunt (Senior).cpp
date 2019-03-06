#include <bits/stdc++.h>
using namespace std;

int visited[1005][1005];
int grid[1005][1005];
int H, W;
char c;

vector<int> adjList[1000005];

int floodFill() {
    // returns how many times the paths needs to split
    // tree stucture, explore from root to leaves -
    // start with robot = 1, + (#children-1) whenever node has more than 1 children
}

int main () {
    freopen("cavein.txt", "r", stdin);
    freopen("caveout.txt","w",stdout);

    scanf("%d %d", &H, &W);
    c = getchar();

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            c = getchar();
            if (c == '.') {
                grid[i][j] = 1; // can visit this space
            }
        }
        c = getchar();
    }
    
    // making the adjacency list
    int counter = 1;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            int 
            if (i == 0 || j == 0) {


    int ans = floodFill();

    printf("%\n", ans);
}
