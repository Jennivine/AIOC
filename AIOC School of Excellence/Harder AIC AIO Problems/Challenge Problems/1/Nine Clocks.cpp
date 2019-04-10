#include <bits/stdc++.h>
using namespace std;

#define NODE 262144

// shortest path from start state to zero state
int adjList[NODE][9];

queue<int> q;
pair<int, int> prevFrom[NODE]; //which node it came from, what move was applied
bool pushed[NODE];

int f(int s, int m);
void intToState(int n, int* state);
int stateToInt(int* state);
void printRoute(int bcState);
void printState(int s);
void followPath (int s, vector<int>& moves);

int MOVE[9][9] = {{1,1,0,1,1,0,0,0,0},
                  {1,1,1,0,0,0,0,0,0},
                  {0,1,1,0,1,1,0,0,0},
                  {1,0,0,1,0,0,1,0,0},
                  {0,1,0,1,1,1,0,1,0},
                  {0,0,1,0,0,1,0,0,1},
                  {0,0,0,1,1,0,1,1,0},
                  {0,0,0,0,0,0,1,1,1},
                  {0,0,0,0,1,1,0,1,1}};

int main() {
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out","w",stdout);
    
    for (int s=1; s < NODE; s++) {
        for (int m=0; m<9; m++) {
            adjList[s][m] = f(s,m);
        }
    }

    int s[9];
    for (int i=0; i<9; i++) {
        scanf("%d", s+i);
    }
        
    //BFS store breadcrumb & move, but keep normal queue
    int start = stateToInt(s);

    int goal[9] = {0,0,0,0,0,0,0,0,0};
    int end = stateToInt(goal);

    prevFrom[start] = make_pair(start, -1);
    q.push(start);
    pushed[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == end) {
            break;
        }

        for (int i=0; i<9; i++) {
            int neighbour = adjList[current][i];
            
            if (pushed[neighbour]) { 
                continue; 
            }
            
            q.push(neighbour);
            pushed[neighbour] = true;
            prevFrom[neighbour] = make_pair(current, i+1);

        }
    }
    
    printRoute(end);
}

//map each possible move to state
int f(int s, int m) {
    //move m applied to state s, return s'
    int state[9];
    intToState(s, state);

    for (int i=0; i<9; i++) {
        state[i] = (state[i] + MOVE[m][i]) % 4;
    }

    return stateToInt(state);
}

//helper function change binary to 3x3 array 
void intToState(int n, int* state) {
    int shift = 8;
    for (int i=0; i<9; i++) {
        state[i] = (n & (3 << shift*2)) >> shift*2;
        shift--;
    }
}   

//helper function change 3x3 array to binary
int stateToInt(int* state) {
    int sum = 0;
    int shift = 8;
    for (int i=0; i<9; i++) {
        sum += state[i] << shift*2;
        shift--;
    }
    return sum;
}

//print the shortest path
void printRoute(int bcState) {
    if (prevFrom[bcState].first == bcState) {
        //printf("%d ", prevFrom[bc].second);
        return;
    }
    
    printRoute(prevFrom[bcState].first);
    printf("%d ", prevFrom[bcState].second);
}

void printState (int s) {
    int state[9];
    intToState(s, state);
    for (int i=0; i<9; i++) {
        printf("%d ", state[i]);
    }
    printf("\n");
}

void followPath (int s, vector<int>& moves) {
    for (auto m:moves) {
        s = adjList[s][m-1];
        printState(s);
    }
}
