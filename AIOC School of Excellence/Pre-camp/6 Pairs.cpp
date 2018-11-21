//
//  pairs.cpp
//
//
//  Created by Jennivine on 21/11/18.

#include <bits/stdc++.h>
using namespace std;

ifstream fin("pairin.txt");
ofstream fout("pairout.txt");

int main(){
    int a;
    fin >> a;
    int arr_one[a] = {0};
    int arr_two[a] = {0};
    
    for (int i=1; i<=a*2; i++){
        int secretNum;
        fin >> secretNum;
        if (arr_one[secretNum-1] == 0){
            arr_one[secretNum-1] = i;
        } else {
            arr_two[secretNum-1] = i;
        }
    }
    
    int currMax = 0;
    
    for (int i=0; i<a; i++){
        if (arr_two[i] - arr_one[i] > currMax){
            currMax = arr_two[i] - arr_one[i];
        }
    }
    
    fout << currMax << "\n";
}
