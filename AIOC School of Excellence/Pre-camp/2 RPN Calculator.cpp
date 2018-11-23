//
//  RPN Calculator.cpp
//
//
//  Created by Jennivine on 23/11/18.
//

#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005

int stackarr[SIZE];
int stackTop = 0;

int popStack();
void pushStack(int value);
void printStack();

ifstream fin("rpnin.txt");
ofstream fout("rpnout.txt");

int main() {
    string a;
    
    while (1) {
        fin >> a;
        if (a == "q") {
            break;
        } else if (a == "p") {
            int val = popStack();
            printStack();
        } else if (a == "+") {
            int val1 = popStack();
            int val2 = popStack();
            pushStack(val1+val2);
            printStack();
        } else if (a == "-") {
            int val1 = popStack();
            int val2 = popStack();
            pushStack(val2-val1);
            printStack();
        } else if (a == "*") {
            int val1 = popStack();
            int val2 = popStack();
            pushStack(val1*val2);
            printStack();
        } else if (a == "/") {
            int val1 = popStack();
            int val2 = popStack();
            pushStack(val2/val1);
            printStack();
        } else if (a == "swap") {
            int val1 = popStack();
            int val2 = popStack();
            pushStack(val1);
            pushStack(val2);
            printStack();
        } else if (a == "dup") {
            int val = popStack();
            pushStack(val);
            pushStack(val);
            printStack();
        } else {
            pushStack(stoi(a));
            printStack();
        }
    }
}

int popStack() {
    int val = stackarr[stackTop-1];
    stackTop--;
    return val;
}

void pushStack(int value) {
    stackarr[stackTop] = value;
    stackTop++;
}

void printStack() {
    if (stackTop == 0){
        fout << "stack is empty!\n";
    } else {
        for (int i=0; i<stackTop; i++){
            fout << stackarr[i] << " ";
        }
        fout << "\n";
    }
}
