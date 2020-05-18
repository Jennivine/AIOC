#include <bits/stdc++.h>
using namespace std;

struct Range {
	int l, r, size;

	friend bool operator < (Range a, Range b) {
		return a.size < b.size || (a.size == b.size && a.l > b.l);	
	}

	friend bool operator > (Range a, Range b) {
		return a.size > b.size || (a.size == b.size && a.l < b.l);
	}
};

priority_queue<Range> pq;

int n, t, b;
int T[30005], B[30005];

int main() {
    freopen("aflin.txt","r",stdin);
    freopen("aflout.txt","w",stdout);
    
    scanf("%d", &n);
	scanf("%d", &t);
    
	for (int i=1; i<=t; i++) 
		scanf("%d", &T[i]);

	// process already taken seats and form the priority queue
	T[++t] = n+1;
	sort(T+1, T+t+1); //inputs are not necessarily in order
	for (int i=1; i<=t; i++) {
		if (T[i] - T[i-1] > 1) {
			pq.push( (Range){T[i-1]+1, T[i]-1, T[i]-T[i-1]-1} );
		}
	}

	scanf("%d", &b);

    for (int i=1; i<=b; i++) {
        int request;
        scanf("%d", &request);
        
        auto largestS = pq.top();
        pq.pop();

        printf("%d\n", largestS.l);
        
		largestS.size -= request;
        largestS.l += request;
        
        if (largestS.size != 0)
            pq.push(largestS);
    }
    
    return 0;
}
