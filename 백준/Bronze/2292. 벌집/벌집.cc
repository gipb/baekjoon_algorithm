#include<iostream>
using namespace std;

int main(){
    int N;
    int norm = 1;
    int cnt = 1;
    cin>>N;
    
    while(N>norm){
        norm += cnt*6;
        cnt++;
    }
    cout<<cnt;
    return 0;
}