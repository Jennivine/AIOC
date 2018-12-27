#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int, int> p1,pair<int,int> p2) {
        if(p1.first == p2.first)
            return p1.second > p2.second;
        else
            return p1.first < p2.first;    // ***EDIT***
    }
};

priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

int n, t, b;
int initB[30005];

void print_queue(priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq) {
    while (not pq.empty()){
        printf("%d,%d\n",pq.top().first,pq.top().second);
        pq.pop();
    }
}

int main() {
    freopen("aflin.txt","r",stdin);
    freopen("aflout.txt","w",stdout);
    
    //Implement own queue that sorts max of first element
    // and min of second element in pair
    
    scanf("%d", &n);
    scanf("%d", &t);
    
    int leftMost = 1;
    for (int i=0; i<t; i++){
        int taken;
        scanf("%d", &taken);
        //printf("%d\n", taken);
        pq.push(make_pair(taken-leftMost, leftMost));
        leftMost = taken+1;
    }
    pq.push(make_pair(n-leftMost+1,leftMost));
    
    //print_queue(pq);
 
    scanf("%d", &b);
    
    for (int i=0; i<b; i++){
        int request;
        scanf("%d", &request);
        //printf("%d\n", request);
        pair<int, int> largestS = pq.top();
        pq.pop();
        printf("%d\n", largestS.second);
        largestS.first -= request;
        largestS.second += request;
        
        if (largestS.first != 0) {
            pq.push(largestS);
        }
    }
    
    return 0;
}
