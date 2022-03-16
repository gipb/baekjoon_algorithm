#include<stdio.h>
#include<stdlib.h>

int main(){
    int N, max, min;
    int* arr;
    scanf("%d",&N);
    
    arr = (int*)malloc(N*sizeof(int));
    
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    
    max = arr[0];
    min = arr[0];
    
    for(int i=1; i<N; i++){
        if(arr[i]>max)
            max=arr[i];
        if(min>arr[i])
            min=arr[i];
    }
    printf("%d %d",min, max);

    free(arr);
    return 0;
}