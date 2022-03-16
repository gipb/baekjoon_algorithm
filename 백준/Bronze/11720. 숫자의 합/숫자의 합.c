#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    int sum=0;
    char* num;
    
    scanf("%d\n",&N);
    num = (char*)malloc((N+1)*sizeof(char));
    fgets(num, N+1, stdin);
    
    for(char* s=num; *s!=0; s++){
        sum += (*s-48);
    }
    printf("%d",sum);
    return 0;
}