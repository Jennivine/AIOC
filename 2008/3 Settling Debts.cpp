#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 1e6+5;

int N, table[MAX_N*2];

int kadane(int a[], int n); 
int maxCircularSum(int a[], int n); 

int main() {
    freopen("debtsin.txt", "r", stdin);
    freopen("debtsout.txt","w",stdout);

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int debt;
        scanf("%d", &debt);
        table[i] = debt*-1;
        table[2*i] = debt*-1;
    }

    printf("%d\n", maxCircularSum(table, N));
}

int maxCircularSum(int a[], int n) { 
    // Case 1: get the maximum sum using standard kadane's algorithm 
    int max_kadane = kadane(a, n); 

    // Case 2: Now find the maximum sum that includes corner elements. 
    int max_wrap = 0, i; 
    for (i=0; i<n; i++) { 
        max_wrap += a[i]; // Calculate array-sum 
        a[i] = -a[i];  // invert the array (change sign) 
    } 

    max_wrap = max_wrap + kadane(a, n); 
    return (max_wrap > max_kadane) ? max_wrap: max_kadane;
}

int kadane(int a[], int n) { 
    int max_so_far = 0, max_ending_here = 0; 
    int i; 
    for (i = 0; i < n; i++) { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_ending_here < 0) 
            max_ending_here = 0; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
    } 
    return max_so_far; 
} 
