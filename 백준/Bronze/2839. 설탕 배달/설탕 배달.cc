#include<iostream>
using namespace std;

int main(){
    int num;
    int cnt=0;
    cin>>num;
    while(num>15){
        num -=5;
        cnt++;
    }
    if(num%5==0)
        cnt += (num/5);
    else if(num%5==1 && num/5>0)
        cnt += (num/5)+1;
    else if(num%5==2&& num/5>1)
        cnt += 4;
    else if(num%5==3)
        cnt += (num/5)+1;
    else if(num%5==4 && num/5>0)
        cnt += (num/5)+2;
    else
        cnt = -1;
    cout<<cnt;
            
    return 0;
}