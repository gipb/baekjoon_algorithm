#include<stdio.h>

int main(){
    int note[8];
    
    for(int i=0; i<8; i++){
        scanf("%d", &note[i]);
    }
    
    if(note[0]!=1 && note[0]!=8)
        printf("mixed");
    else if(note[0]==1){
        for(int i = 1; i<8; i++){
            if(note[i] == i+1){
                if(i==7)
                    printf("ascending");
                continue;
            }
                
            else{
                printf("mixed");
                break;
            }
        }
    }
    else{
        for(int i=1; i<8; i++){
            if(note[i] == 8-i){
                if(i==7)
                    printf("descending");
                continue;
            }
            else{
                printf("mixed");
                break;
            }
        }
    }
    
    return 0;
}