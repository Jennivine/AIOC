#include <bits/stdc++.h>
using namespace std;
vector<int> connection[305];
int ans;
int checked[305];
int hasPath(int p, int q);


int main (){
    freopen("gossin.txt","r",stdin);
    freopen("gossout.txt","w",stdout);
    
    int n;
    scanf("%d", &n);
    int a,b;
    int p,q;
    
    while (1) {
        scanf("%d %d", &a, &b);
        if ((a < 0) || (b < 0)){
            break;
        } else {
            connection[a].push_back(b);
            connection[b].push_back(a);
        }
    }
    
    while (1) {
        scanf("%d %d", &p, &q);
        if ((p < 0) && (q < 0)) {
            break;
        } else {
            for (int i=0; i<n; i++) {
                checked[i] = 0;
            }
            ans = hasPath(p,q);
            if (ans == 1){
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
}

int hasPath(int p, int q) {
    if (checked[p]) {
        return 0;
    }
    if (p == q) {
        return 1;
    }
    checked[p] = 1;
    for (auto y:connection[p]){
        if (hasPath(y,q)){
            return 1;
        }
    }
    return 0;
}
