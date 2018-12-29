#include <bits/stdc++.h>
using namespace std;
vector<int> duel[100005];
int painted[100005];
int a,b;
vector<int> white;
vector<int> black;
long m;

void invitation (int x, int colour);

int main(){
    freopen("arthin.txt", "r", stdin);
    freopen("arthout.txt", "w", stdout);

    int N, P;
    scanf("%d", &N);
    scanf("%d", &P);
    
    for (int i=0; i<P; i++) {
        scanf("%d %d", &a, &b);
        duel[a].push_back(b);
        duel[b].push_back(a);
    }
    
    for (int i=1; i<=N; i++){
        if (painted[i]) {
            continue;
        } else {
			//printf("%d\n",i);
            invitation(i,0);
            m += max(white.size(),black.size());
            white.clear();
            black.clear();
        }
    }
    
    printf("%ld\n", m);
    
}

void invitation (int x, int colour) {
    // colour = 0 (black) or 1 (white)
    if (painted[x]){
        return;
    }
    painted[x] = 1;
    if (colour == 1) {
        white.push_back(x);
        for (auto i:duel[x]){
            invitation(i, 0);
        }
    } else {
        black.push_back(x);
        for (auto i:duel[x]){
            invitation(i,1);
        }
    }
}
