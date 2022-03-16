#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c;
    
    while(scanf("%lf %lf %lf", &a, &b, &c)){
        if((a+b+c)==0)
            break;
        if(c>=a){
            if(b>c){
                int temp = b;
                b = c;
                c = temp;
            }
        }
        else{
            if(b>a){
                int temp = b;
                b = c;
                c = temp;
            }
            else{
                int temp = a;
                a = c;
                c = temp;
            }
        }
        
        if(pow(a,2)+ pow(b,2)==pow(c,2))
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}