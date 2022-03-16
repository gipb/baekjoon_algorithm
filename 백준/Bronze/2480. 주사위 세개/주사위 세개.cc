#include<stdio.h>

int max(int a, int b, int c);

int main(){
    int a;
    int b;
    int c;
    
    scanf("%d %d %d",&a, &b, &c);
    
    if(a==b){
        if(b==c)
            printf("%d", 10000+a*1000);
        else
            printf("%d", 1000+a*100);
    }
    else{
        if(b==c)
            printf("%d", 1000+b*100);
        else if(a==c)
            printf("%d", 1000+a*100);
        else
            printf("%d", max(a,b,c)*100);
    }
    return 0;
}

int max(int a, int b, int c){
    if(a>b){
        if(a>c)
            return a;
        else
            return c;
    }
    else{
        if(b>c)
            return b;
        else
            return c;
    }
}