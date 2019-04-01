#include <bits/stdc++.h>
using namespace std;

long long N, heights[500005], ans;
stack <long long> s1, s2, s3;

int main() {
    freopen("skysurf.in", "r", stdin);
    freopen("skysurf.out","w",stdout);

    scanf("%lld", &N);
    for (int i=0; i<N; i++) {
        scanf("%lld", heights+i);
    }

    heights[N] = 1e12;
    
    for (int i=0; i<N; i++) {
        long long n = 0;
        while (!s1.empty() && s1.top() < heights[i]) {
            n++;
            s1.pop();
        }
        s1.push(heights[i]);
        ans += n;
    }

    for (int i=N-1; i>=0; i--) {
        long long n = 0;
        while (!s2.empty() && s2.top() < heights[i]) {
            n++;
            s2.pop();
        }
        s2.push(heights[i]);
        ans += n;
    }

    for (int i=0; i<=N; i++) {
        long long last = -1;
        long long n = 1;
        while (!s3.empty() && s3.top() < heights[i]) {
            if (s3.top() == last) {
                n++;
            } else {
                ans += (n*(n-1))/2;
                last = s3.top();
                n = 1;
            }
            s3.pop();
        }
        ans += (n*(n-1))/2;
        s3.push(heights[i]);
    }

    printf("%lld\n", ans);
}
