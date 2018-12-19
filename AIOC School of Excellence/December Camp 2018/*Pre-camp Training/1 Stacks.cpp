//
//  stacks.cpp
//  
//
//  Created by Jennivine on 23/11/18.

#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000
int stackarray[SIZE];

int stacktop = 0;

void stackpush(int value){
    stackarray[stacktop] = value;
    stacktop++;
}

int stackpop(){
    int retval = stackarray[stacktop-1];
    stacktop--;
    return retval;
}

ifstream fin("stacksin.txt");
ofstream fout("stacksout.txt");

int main(){
    string a;
    
    while (1){
        fin >> a;
        if (a == "q"){
            break;
        } else if (a == "p"){
            // pop
            int val = stackpop();
            // print
            if (stacktop == 0){
                fout << "stack is empty!\n";
            } else {
                for (int i=0; i<stacktop; i++){
                    fout << stackarray[i] << " ";
                }
                fout << "\n";
            }
        } else {
            // append
            
            stackpush(stoi(a));
            //print
            for (int i=0; i<stacktop; i++){
                fout << stackarray[i] << " ";
            }
            fout << "\n";;
        }
    }
}
