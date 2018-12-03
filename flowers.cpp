#include <bits/stdc++.h>
using namespace std;

int values[100][100];
int best[100][100];

ifstream fin("flower.inp");
ofstream fout("flower.out");

int main (){
  int F, V;
  fin >> F;
  fin >> V;

  for (int row=0; row<F; row++){
    for (int col=0; col<V; col++){
      int a;
      fin >> a;
      values[row][col] = a;
    }
  }

  int Max = -1000000;
  int vases[105];

  for (int row=0; row<F; row++){
    for (int col=0; col<V; col++){
      if ((row == 0) && (col == 0)) {
        best[row][col] = values[row][col];
      } else if (row == 0) {
        best[row][col] = max(values[row][col],
                             values[row][col-1]);
      } else if (col == 0) {
        best[row][col] = -1000000;
      } else {
        best[row][col] = max(best[row-1][col-1]+values[row][col],
                             best[row][col-1]);
      }

      if (best[row][col] > Max){
        Max = best[row][col];
        vases[row] = col+1;
      }
    }
  }

  fout << best[F-1][V-1] << "\n";

  for (int i=0; i<F; i++){
    fout << vases[i] << " ";
  }
  fout << "\n";
}
