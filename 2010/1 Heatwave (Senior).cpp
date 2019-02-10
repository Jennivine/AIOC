#include <bits/stdc++.h>
using namespace std;

int N, H;
int temp[100005];
int heatwave;

int main() { 
    freopen("heatin.txt", "r", stdin);
    freopen("heatout.txt","w",stdout);

    scanf("%d %d", &N, &H);
    for (int i=0; i<N; i++) {
        scanf("%d", temp+i);
    }

    int streak = 0;
    for (int i=0; i<N; i++) {
        if (temp[i] >= H) {
            heatwave++;
        } else {
            if (heatwave > streak) {
                streak = heatwave;
            } 
            heatwave = 0;
        }
    }

    if (heatwave > streak) {
        streak = heatwave;
    }
    printf("%d\n", streak);
}

