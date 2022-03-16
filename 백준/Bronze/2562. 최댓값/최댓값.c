#include<stdio.h>

int main(){
    int max = 0;
    int index, num;
    
    for(int i=1; i<10; i++){
        scanf("%d\n",&num);
        if(num>max){
            max = num;
            index = i;
        }
    }
    
    printf("%d\n%d", max, index);
    
    return 0;
    
}