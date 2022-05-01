#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int recur(int num) {
	if (dp[num]) return dp[num];
	if (num == 1) return dp[num] = 1;
	if (num == 2) return dp[num] = 3;
	
	return dp[num] = (recur(num - 1) + recur(num - 2)*2)%10007;
}

int main() 
{
	int N;
	cin >> N;
	
	dp = vector<int>(N + 1, 0);

	cout << recur(N);
	return 0;
}