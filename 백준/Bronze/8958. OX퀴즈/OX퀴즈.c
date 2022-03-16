#include<stdio.h>

int main(){
    int N;
    int cnt=0;
    int sum=0;
    char buf[80]={0,};
    
    scanf("%d\n",&N);
    for(int i=0; i<N; i++){
        sum=0;
        cnt=0;
        scanf("%s",buf,sizeof(buf));
        for(char* s=buf; *s!=0; s++){
            if(*s=='O'){
                cnt++;
                sum += cnt;
            }
            else{
                cnt=0;
            }
        }
        if(i!=N-1)
            printf("%d\n",sum);
        else
            printf("%d",sum);
    }
    return 0;
}