#include<stdio.h>

int main(){
    int a;
    int b;
    double ans;
    scanf("%d %d", &a, &b);
    ans = a/(double)b;
    printf("%.10lf",ans);
    return 0;
}