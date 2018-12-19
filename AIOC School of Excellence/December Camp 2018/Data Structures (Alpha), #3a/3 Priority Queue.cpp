#include <bits/stdc++.h>
using namespace std;
int N;
int max_Heap[1000005];
int lastEle = 0;

void printHeap();
void popHeap(int lastEle);
void pushHeap(int input, int lastEle);


int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int input;
        scanf("%d", &input);
        if (input == 0) {
            printHeap();
            popHeap(lastEle);
            lastEle--;
            /*
             printf("pop: ");
             for (int i=1; i<=lastEle; i++){
             printf("%d ", max_Heap[i]);
             }
             printf("\n");
             */
        } else {
            lastEle++;
            pushHeap(input, lastEle);
            /*
             printf("push: ");
             for (int i=1; i<=lastEle; i++){
             printf("%d ", max_Heap[i]);
             }
             printf("\n");
             */
        }
    }
}

void printHeap(){
    printf("%d\n", max_Heap[1]);
}

void popHeap(int lastEle){
    max_Heap[1] = max_Heap[lastEle];
    max_Heap[lastEle] = 0;
    int index = 1;
    while (index*2 < lastEle) {
        int childL = max_Heap[index*2];
        int childR = max_Heap[index*2+1];
        int largestL;
        
        if (childR == 0) {
            if (max_Heap[index] >= childL) {
                break;
            }
            largestL = index*2;
        } else {
            if (max_Heap[index] >= childL && max_Heap[index] >= childR) {
                break;
            }
            int child = max(childL, childR);
            if (child == childL) {
                largestL = index*2;
            } else {
                largestL = index*2 + 1;
            }
        }
        
        int i = max_Heap[index];
        max_Heap[index] = max_Heap[largestL];
        max_Heap[largestL] = i;
        index = largestL;
    }
}

void pushHeap(int input, int lastEle) {
    max_Heap[lastEle] = input;
    int index = lastEle;
    while (index != 1){
        if (max_Heap[index] <= max_Heap[index/2]) {
            break;
        }
        int i = max_Heap[index];
        max_Heap[index] = max_Heap[index/2];
        max_Heap[index/2] = i;
        index = index/2;
    }
}
