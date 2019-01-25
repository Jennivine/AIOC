#include <bits/stdc++.h>
using namespace std;
void operations(int N, int i, int ope);
string operation[105];
int target; //target number to reach
int operLeft; //how many operations left to use

void printOp() {
    for (auto i : operation){
        cout << i;
    }
    cout << "\n";
}

int main() {
    cin >> target;
    cin >> operLeft;
    
    operations(1, 0, operLeft);
}

void operations(int N, int i, int ope){
    if (N == target) {
        printOp();
    } else if ((N > target) || (ope == 0)) {
        cout << "\n";
        return;
    } else {
        operation[i] = "+";
        operations(N+1, i+1, ope-1);
        
        operation[i] = "*";
        operations(N*2, i+1, ope-1);
    }
}
