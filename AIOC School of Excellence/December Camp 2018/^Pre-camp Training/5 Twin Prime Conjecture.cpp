//
//  prime.cpp
//
//
//  Created by Jennivine on 18/11/18.

#include <cstdio>
#define TRUE 1
#define FALSE 0

int main(){
    freopen("primein.txt","r",stdin);
    freopen("primeout.txt","w", stdout);
    
    int n;
    scanf("%d",&n);
    
    bool not_prime[n+1] = {FALSE};
    not_prime[0] = TRUE;
    not_prime[1] = TRUE;
    not_prime[2] = FALSE;
    
    for (int i=3; i<(n/2)+1; i+=2){
        int index = i*2;
        while (index <= n){
            not_prime[index] = TRUE;
            index += i;
        }
    }
    
    printf("2\n");
    
    for (int i=3; i<n+1;i+=2){
        if (! not_prime[i]){
            printf("%d\n",i);
        }
    }
}
