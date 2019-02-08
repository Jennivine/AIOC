//
//  fashion.cpp
//  
//
//  Created by Jennivine on 17/11/18.

#include <cstdio>

int main(){
    freopen("fashin.txt","r",stdin);
    freopen("fashout.txt","w", stdout);
    
    int a;
    scanf("%d",&a);
    int notes = 0;
    
    
    while (a != 0){
        if (a >= 100) {
            notes += a/100;
            a = a % 100;
        } else if (a >= 20) {
            notes += a/20;
            a = a % 20;
        } else if (a >= 5) {
            notes += a/5;
            a = a % 5;
        } else {
            notes += a;
            a = 0;
        }
    }
    
    printf("%d\n",notes);
}
