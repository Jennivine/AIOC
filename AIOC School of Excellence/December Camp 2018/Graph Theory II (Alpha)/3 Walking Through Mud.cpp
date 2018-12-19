//
//  mud.cpp
//  
//
//  Created by Jennivine on 19/12/18.

#include <bits/stdc++.h>
using namespace std;

vector<int> Map[26];
queue<int> q;

int pushed[26];
int previous[26];
int k,n;
int current;
int exist;

void printRoute(int breadcrumb);

int main(){
    freopen("mudin.txt", "r", stdin);
    freopen("mudout.txt", "w", stdout);
    
    scanf("%d", &k);
    
    //Useless input; reading in, then discard it
    for (int i=0; i<k; i++){
        int s;
        scanf("%d", &s);
    }
    
    //Reading in + constructing the graph
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        
        Map[a].push_back(b);
        Map[b].push_back(a);
    }
    
    /*
    for (int i=0; i<n; i++) {
        printf("%d: ", i);
        for (auto a:Map[i]) {
            printf("%d ",a);
        }
        printf("\n");
    }
    */
    
    int start, end;
    scanf("%d %d", &start, &end);

    //BFS for shortest path from start to end
    q.push(start);
    pushed[start] = 1;
    previous[start] = start;
    
    while (q.size()){
        current = q.front();
        q.pop();
        if (current == end){
            exist = 1;
            break;
        }
        for (auto N:Map[current]){
            if (pushed[N]){
                continue;
            }
            previous[N] = current;
            q.push(N);
            pushed[N] = 1;
        }
    }
    
    if (exist){
        printRoute(end);
        printf("\n");
    } else{
        printf("No route exists.\n");
    }
}

void printRoute(int breadcrumb) {
    if (previous[breadcrumb] == breadcrumb) {
        printf("%d ", breadcrumb);
        return;
    }
    printRoute(previous[breadcrumb]);
    printf("%d ", breadcrumb);
}
