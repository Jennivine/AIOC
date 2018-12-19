#include <bits/stdc++.h>
using namespace std;

int days[100005];
int cache[100005];
int filled[100005];
int price1, days1;
int price2, days2;

int ticket (int i, int lastDay){
    if (filled[i]){
        return cache[i];
    }
    if (i > lastDay){
        return 0;
    } else if (days[i] == 0 ){
        return ticket(i+1, lastDay);
    } else {
        cache[i] = min(price1+ticket(i+days1,lastDay),price2+ticket(i+days2,lastDay));
        filled[i] = 1;
        return cache[i];
    }
}

int main (){
    freopen("ticketin.txt","r",stdin);
    freopen("ticketout.txt","w", stdout);
    scanf("%d %d", &price1, &days1);
    scanf("%d %d", &price2, &days2);
    
    int totalDays;
    scanf("%d", &totalDays);
    
    int lastDay;
    
    for (int i=0; i<totalDays; i++){
        int travel;
        scanf("%d", &travel);
        days[travel] = 1;
        
        if (i == totalDays-1){
            lastDay = travel;
        }
    }
    
    int ans = ticket(1,lastDay);
    printf("%d\n", ans);
    
}
