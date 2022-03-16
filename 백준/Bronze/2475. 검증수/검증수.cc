#include<stdio.h>

int main(){
    
    int pw;
    int key=0;
    for (int i =0; i<5; i++){
        scanf("%d",&pw);
        key += (pw*pw);
    }
    
    printf("%d", key%10);    
    
    return 0;
}