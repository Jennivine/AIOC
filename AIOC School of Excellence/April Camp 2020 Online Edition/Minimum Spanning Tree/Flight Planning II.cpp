#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MAX = 100005;
long long cost;

vector<Flight> paths(MAX);

struct Flight{
	int to, from, cost;
	bool operator < (const Flight& other) const {
		return (cost < other.cost);
	}
};

// within each country, ensure a MST is constructed
// then construct MST between countries
