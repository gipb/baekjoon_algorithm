#include <iostream>
#include <vector>
using namespace std;

int Max_(int a, int b, int c){
    if(a>b){
        if(a>c) return a;
        else return c;
    }
    else{
        if(b>c) return b;
        else return c;
    }
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int N = land.size();
    for(int i=1; i<N;i++){
        for(int j=0; j<4; j++){
            land[i][j] += 
                Max_(land[i-1][(j+1)%4], 
                     land[i-1][(j+2)%4], 
                     land[i-1][(j+3)%4]);
        }
    }
    
    answer = land[N-1][0];
    for(int i=1; i<4; i++){
        if(answer < land[N-1][i]) answer = land[N-1][i];
    }
    
    return answer;
}