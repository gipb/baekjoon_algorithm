#include<stdio.h>

int main(){
    int L;
    int P;
    int paper[5]={};
    
    scanf("%d %d",&L, &P);
    for(int i=0; i<5; i++){
        scanf("%d",&paper[i]);
        paper[i] -= L*P;
    }
    
    for(int i=0; i<5; i++){
        printf("%d ",paper[i]);
    }
    
    return 0;    
    
}