#include <bits/stdc++.h>
using namespace std;

int people[1005];
int totP; //number of problems
int num;  //number of people

int main() {
    freopen("genin.txt", "r", stdin);
    freopen("genout.txt","w",stdout);

    scanf("%d %d", &num, &totP);

    int counter = 1;
    int index = 0;
   
    while (totP > 0) {
        people[index] += min(totP,counter);
        totP -= counter;
        counter++;
        index = (index+1)%num;
    }

    int genius;
    for (int i=0; i<num; i++) {
        if (people[i] > people[genius]) {
            genius = i;
        }
    }

    printf("%d %d\n", genius+1, people[genius]);
}

