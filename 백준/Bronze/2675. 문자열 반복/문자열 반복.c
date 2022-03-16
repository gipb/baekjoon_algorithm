#include<stdio.h>
#include<stdlib.h>

int main(){
    int T;
    int R;
    char S[21]={0,};

    scanf("%d", &T);
    
    for(int i=0; i<T; i++){
        scanf("%d %s",&R, &S);
        for(char* s=S; *s!=0; s++){
            for(int j=0; j<R; j++){
                printf("%c",*s);
            }
        }
        printf("\n");
    }
    
    return 0;
}