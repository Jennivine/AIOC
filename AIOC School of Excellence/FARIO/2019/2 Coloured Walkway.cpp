#include <bits/stdc++.h>
using namespace std;

int n, c, p, path[100005], tile[100005];
set <int> colour[100005]; // colour x is compatible with colours <a,b,c,..>
vector <int> cIndex[100005]; // colour x is used on tiles <a,b,c,...> (index)

int ans;

int main() {
    //freopen("out.txt","w",stdout);

    scanf("%d %d", &n, &c);
    for (int i=0; i<n; i++) {
        scanf("%d", tile+i);
        cIndex[tile[i]].push_back(i);
    }

    scanf("%d", &p);
    for (int i=0; i<p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        colour[a].insert(b);
        colour[b].insert(a);
    }

    path[0] = 0;
    for (int i=1; i<n; i++) {
        int c = tile[i];
        //printf ("colour: %d\n", c);
        ans = 0;
        int hasPath = 0;
        for (auto cc:colour[c]) {
            hasPath = 1;
            //printf("compatible with: %d\n", cc);
            for (auto idx:cIndex[cc]) {
                //printf("at index: %d\n", idx);
                if (idx < i) {
                    ans += path[idx];
                }
            }
        }
        if (hasPath) {
            path[i] = (ans+1) % 1000000007;
        } else {
            path[i] = 0;
        }
        
        //printf("%d\n", path[i]);
        //printf("\n");
    }

    printf("%d\n", path[n-1]);

}


