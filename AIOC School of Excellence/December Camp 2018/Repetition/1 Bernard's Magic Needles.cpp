#include <bits/stdc++.h>
using namespace std;

ifstream fin("bernardin.txt");
ofstream fout("bernardout.txt");
string needleSearch(int needle, int N);

int a[100005];

int main(){
  int N;
  fin >> N;
  int i = 0;

  while (i < N){
    fin >> a[i];
    i++;
  }

  while (1){
    int needle;
    fin >> needle;
    if (needle == -1){
      break;
    } else {
      string ans = needleSearch(needle,N);
      fout << ans << "\n";
    }
  }
}

string needleSearch(int needle, int N){
  int lo = 0;
  int hi = N;
  while (lo != hi){
    int mid = (lo+hi)/2;
    if (a[mid] < needle){
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  if (a[lo] == needle){
    return to_string(lo+1);
  } else {
    return "needle is gone forever";
  }
}
