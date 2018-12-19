#include <bits/stdc++.h>
using namespace std;

int arr[3][500005];
int linear[500005];
int cumMax[500005];


int main() {
    int len;
    scanf("%d",&len);
    
    for (int i=0; i<len; i++){
        int a,b,c;
        scanf("%d",&a);
        arr[0][i] = a;
        
        scanf("%d",&b);
        arr[1][i] = b;
        
        scanf("%d",&c);
        arr[2][i] = c;
    }
    
    len--;
    for (int i=0; i<len; i++){
        int step1 = arr[0][i] + arr[0][i+1] + arr[1][i] + arr[1][i+1];
        int step2 = arr[1][i] + arr[1][i+1] + arr[2][i] + arr[2][i+1];
        linear[i] = max(step1,step2);
    }
    
    cumMax[len] = 0;
    cumMax[len-1] = max(0, linear[len-1]);
    for (int i=len-2; i>=0; i--){
        cumMax[i] = max(cumMax[i+2]+linear[i],cumMax[i+1]);
    }
    
    printf("%d\n", cumMax[0]);
}
