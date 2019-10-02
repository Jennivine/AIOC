#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<pair<int,int> > cities[505];

queue<int> possibleLocations;
int newPlaces[505];


int main() {
    freopen("wherein.txt", "r", stdin);
    freopen("whereout.txt","w",stdout);

    scanf("%d %d", &N, &M);

    for (int i=0; i<M;i++) {
        int A,B,C;
        scanf("%d %d %d", &A, &B, &C);
        cities[A].push_back(make_pair(B,C));
        cities[B].push_back(make_pair(A,C));
    }

    int K;
    scanf("%d", &K);

    for (int i=0; i<K; i++) {
        int transport;
        scanf("%d", &transport);
        
        if (i == 0) {
            //initialise queue
            for (int i=1; i<=N; i++){
                for (auto route:cities[i]){
                    if (route.second == transport) {
                        newPlaces[route.first] = 1;
                    }
                }
            }
        } else {
            //create set for where CS could be next
            while (!possibleLocations.empty()){
                int place = possibleLocations.front();
                possibleLocations.pop();
                for (auto route:cities[place]) {
                    if (route.second == transport) {
                        newPlaces[route.first] = 1;
                    }
                }
            }
        }
        //update queue
        for (int i=1; i<=N; i++) {
            if (newPlaces[i] == 1) {
                possibleLocations.push(i);
                newPlaces[i] = 0;
            }
        }
    }


    if (possibleLocations.empty()){
        printf("Impossible\n");
    } else {
        while (!possibleLocations.empty()){
            printf("%d\n", possibleLocations.front());
            possibleLocations.pop();
        }
    }
}
    
		
