#include<stdio.h>

int main(){
    int arr[4]={0,}; // x, y, w, h
    int min = 1000;
    scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
    
    arr[2] -= arr[0];
    arr[3] -= arr[1];
    
    for(int i=0; i<4; i++){
        if(min>arr[i])
            min = arr[i];
    }
    
    printf("%d", min);
    
    return 0;    
}