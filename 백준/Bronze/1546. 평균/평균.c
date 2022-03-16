#include<stdio.h>

int main(){
    int N;
    int M = 0;
    double sum = 0;
    int score[1000]={0,};

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d", &score[i]);
    }
    for(int i=0;i<1000;i++){
        sum += score[i];
        if(score[i]>M)
            M = score[i];
    }
    
    printf("%lf",(sum/N)*100.0/M);
    
    return 0;
}