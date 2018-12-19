//
//  queues.cpp
//
//
//  Created by Jennivine on 23/11/18.

#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000
int queuearray[SIZE];
int queuefront = 0;
int queueback = 0;

void queuepush(int value){
    queuearray[queueback % SIZE] = value;
    queueback++;
}

int queuepop(){
    int retval = queuearray[queuefront % SIZE];
    queuefront++;
    return retval;
}

bool queueEmpty(){
    return (queueback == queuefront);
}

ifstream fin("queuesin.txt");
ofstream fout("queuesout.txt");

void printQueue() {
    if (queueEmpty()){
        fout << "queue is empty!\n";
    } else {
        for (int i=queuefront; i<queueback; i++){
            fout << queuearray[i%SIZE] << " ";
        }
        fout << "\n";
    }
}

int main(){
    int a;
    
    while (1){
        fin >> a;
        
        if (a == -2){
            break;
        } else if (a == -1){
            // pop
            int val = queuepop();
            // print
            printQueue();
        } else {
            // append
            queuepush(a);
            //print
            printQueue();
        }
    }
}
