#include "flip.h"
#include <bits/stdc++.h>
using namespace std;
map<char, vector<int> > cards;

int main() {
  getC();

  for (int i=1; i<=50; i++) {
    char face = faceup(i);
    cards[face].push_back(i);
  }

  for (int i='A'; i<='Y'; i++) {
    int first = cards[i].front();
    int second = cards[i].back();

    faceup(first);
    faceup(second);
  }
}
