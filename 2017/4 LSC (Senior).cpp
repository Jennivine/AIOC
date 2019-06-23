#include <bits/stdc++.h>
using namespace std;

int N, L;
int A[100000];

// shop indicies in terms of how close they are to the target position
int shops[100000]; 

pair<int, int> curRange;
pair<int, int> newRange;

pair<int, int> consider (int i, int j);
void updateRange();

int main() {
    freopen("lscin.txt", "r", stdin);
    freopen("lscout.txt","w",stdout);

    scanf("%d %d", &N, &L);
    for (int i=1; i<=N; i++) {
        scanf("%d", A+i);
    }

    for (int i=1; i<=N; i++) {
        int index;
        scanf("%d", &index);
        shops[i] = A[index];
    }
   
    curRange = make_pair(1, L);

    for (int i=1; i<N; i++) {
        // compare shops i and i+1;
        newRange = consider(i, i+1);
        updateRange();
    }

    printf("%d\n", curRange.first);
}

pair<int, int> consider(int i, int j) {
    pair<int, int> range;
    
    if (shops[i] > shops[j]) {
        range = make_pair((shops[i]+shops[j])/2, L);
    } else if (shops[i] < shops[j]) {
        range = make_pair(1, (shops[i]+shops[j])/2);
    }
    
    return range;
}

void updateRange() {
    int left, right;
    left = max(curRange.first, newRange.first);
    right = min(curRange.second, newRange.second);
    
    if (left > right) {
        left = -1;
        right = -1;
    }

    curRange = make_pair(left, right);
}
