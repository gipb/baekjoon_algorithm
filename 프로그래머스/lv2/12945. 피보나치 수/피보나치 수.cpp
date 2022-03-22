#include <string>
#include <vector>

using namespace std;
#define DIV 1234567

vector<int> dp(100000,0);

int fibo(int n){
    if(dp[n]) return dp[n];
    if(n==0) {
        dp[0] = 0;
        return dp[0];
    }
    if(n==1) {
        dp[1] = 1;
        return dp[1];
    }
    dp[n] = (fibo(n-1) + fibo(n-2))%DIV;
    return dp[n];
}

int solution(int n) {
    int answer = 0;
    answer = fibo(n);
    return answer;
}