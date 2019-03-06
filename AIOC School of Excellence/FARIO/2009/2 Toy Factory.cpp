#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int N, C, K;

int toys[MAXN], Count[MAXN];
bool open[MAXN]; // if true - tin at index i is open

set <pair<int, int> > tins; // set of <next index, colour> pairs
vector <int> V[MAXN]; // V[c] -> all indices to be painted colour c
int ans;

int main() {
    scanf("%d %d %d", &N, &C, &K);

    for (int i=1; i<=N; i++) {
        scanf("%d", toys+i);
		V[toys[i]].push_back(i);
    }
	
	for (int i=1; i<=N; i++) { V[toys[i]].push_back(N+1); }
	
	for (int i=1; i<=N; i++) {
		int c = toys[i]; // colour of tin at index i
		
		if (open[c]) {
			tins.erase(tins.find(make_pair(-V[c][Count[c]], c)));
			tins.insert(make_pair(-V[c][++Count[c]], c));
			continue;
		}
		
		if (tins.size() < K) {
			tins.insert(make_pair(-V[c][++Count[c]], c));
			open[c] = true;
			ans++;
		} else {
			open[(tins.begin()) -> second] = false;
			tins.erase(tins.begin());
			tins.insert(make_pair(-V[c][++Count[c]], c));
			open[c] = true;
			ans++;
		}
	}

    printf("%d\n", ans);
}