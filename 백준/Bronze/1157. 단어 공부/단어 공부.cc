#include<stdio.h>
#include<stdlib.h>

int main(){
    char* string;
    char* s;
    int max_size = 1000001;
    int alpha_array[26]={0,};
    int i;
    int max=0;
    int cnt=0;
    int index;
    
    string = (char*)malloc(max_size*sizeof(char));
    
    fgets(string, max_size, stdin);
    s = string;
    
    while(*s){
        if(*s<97)
            alpha_array[*s-65] += 1;
        else
            alpha_array[*s-97] += 1;
        s++;
    }
    
    for(i=0; i<26; i++){
        if(alpha_array[i]>max)
            max = alpha_array[i];
    }
    
    for(i=0; i<26; i++){
        if(alpha_array[i]==max){
            cnt++;
            index=i;
        }
    }
    
    if(cnt==1)
        printf("%c", index+65);
    else
        printf("?");
    
    free(string);
    return 0;
}