#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MAX = 100005;
long long costSaved;

struct Flight{
	int to, from, cost;
	bool operator < (const Flight& other) const {
		return (cost < other.cost);
	}
};

// cityPath[i] -> domestic flight paths of country i
map<int, vector<Flight> > cityPaths;

// international flights between countries
vector<Flight> countryPaths(MAX); 

int cityCountry[MAX]; // cityCountry[i] -> Country name of city i

// within each country, ensure a MST is constructed
// then construct MST between countries

int parentCity[MAX], parentCountry[MAX];

void make_set(int N) {
	for (int i=1; i<=N; i++) {
		parentCity[i] = i;
		parentCountry[i] = i;
	}
}

int union_find(int a, int op) {
	if (op == 1) {
		// searching for the rep of a city
		if (parentCity[a] == a) return a;
		return parentCity[a] = union_find(parentCity[a], 1);
	} else if (op == 2) {
		// searching for the rep of a country
		if (parentCountry[a] == a) return a;
		return parentCountry[a] = union_find(parentCountry[a], 2);
	}
}

void union_join(Flight f, int op) {
	int a = union_find(f.to, op);
	int b = union_find(f.from, op);

	if (a != b) {
		// join the two subtrees;
		if (op == 1) {
			parentCity[a] = b;
		} else if (op == 2) {
			parentCountry[a] = b;
		}
	} else {
		costSaved += f.cost;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	make_set(N);

	for (int i=1; i<=N; i++) {
		cin >> cityCountry[i];
	}

	for (int i=1; i<=M; i++) {
		int to, from, cost;
		Flight f;

		cin >> to >> from >> cost;
		if (cityCountry[to] == cityCountry[from]) {
			f.to = to;
			f.from = from;
			f.cost = cost;
			cityPaths[cityCountry[to]].push_back(f);
		} else {
			f.to = cityCountry[to];
			f.from = cityCountry[from];
			f.cost = cost;
			countryPaths.push_back(f);
		}
	}

	for (auto paths : cityPaths) {
		sort(paths.second.begin(), paths.second.end());
		for (Flight p : paths.second) {
			union_join(p,1);
		}
	}

	sort(countryPaths.begin(), countryPaths.end());
	for (Flight p : countryPaths) {
		union_join(p,2);
	}

	cout << costSaved << "\n";
}
