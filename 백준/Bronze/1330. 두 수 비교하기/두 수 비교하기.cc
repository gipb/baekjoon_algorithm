#include<stdio.h>

int main(){
    short A;
    short B;
    short compare;
    
    scanf("%hd %hd",&A, &B);
    
    compare = A-B;
    if(compare > 0)
        printf(">");
    else if(compare == 0)
        printf("==");
    else
        printf("<");
    
    return 0;
}