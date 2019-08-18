#include <bits/stdc++.h>
using namespace std;

#define ROOT 0

struct NODE {
	char letter;
	int children[26];
	int currDepth;
	bool terminator;
	int parent;
} ;

string input;
int n, currNode, idx;
char letter;
NODE nodes[200000];

deque<int> pathToNode(int Id);

int main () {
	// hacky magic to make life easier
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	freopen("chains.in", "r", stdin);
	freopen("chains.out","w",stdout);

	cin >> input;
	nodes[0].terminator = true;

	while (input != ".") {
		n = input.length();
		idx = ROOT;

		for (int i=0; i<n; i++) {
			letter = input[i]; //character between 'a' and 'z' inclusive
			
			if (nodes[idx].children[letter-'a'] != 0) {
				idx = nodes[idx].children[letter-'a'];
				continue;
			}
			
			// update children of parent node
			nodes[idx].children[letter-'a'] = ++currNode;
		
			// create struct of letter
			nodes[currNode].letter = letter;
			nodes[currNode].parent = idx;
			nodes[currNode].terminator = (i == n-1);
			
			if (nodes[idx].terminator == true) {
				nodes[currNode].currDepth = nodes[idx].currDepth + 1;
			} else {
				nodes[currNode].currDepth = nodes[idx].currDepth;
			}
			
			idx = currNode;
		}

		cin >> input;
	}

	// now find the node with the max depth
	int maxDepth = 0;
	int maxId = 0;
	for (int i=0; i<=currNode; i++) {
		if (nodes[i].currDepth >= maxDepth) {
			maxDepth = nodes[i].currDepth;
			maxId = i;
		}
	}

	// backtrack from maxId to the root, and then print the words according to terminators
	deque<int> breadcrumbs = pathToNode(maxId);

	string answer = "";
	for (auto i:breadcrumbs) {
		if (i == 0) {
			continue;
		}

		answer += nodes[i].letter;
		if (nodes[i].terminator) {
			cout << answer << endl;
		}
	}
}

deque<int> pathToNode(int Id) {
	deque<int> path;
	path.push_front(Id);

	while (Id != 0) {
		Id = nodes[Id].parent;
		path.push_front(Id);
	}

	return path;
}