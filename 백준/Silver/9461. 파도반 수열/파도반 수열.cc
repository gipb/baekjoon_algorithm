#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(100,0);

long long recur(int num) {
	if (dp[num]) return dp[num];
	if (num == 0) return dp[num] = 1;
	if (num == 1) return dp[num] = 1;
	if (num == 2) return dp[num] = 1;
	if (num == 3) return dp[num] = 2;
	if (num == 4) return dp[num] = 2;

	return dp[num] = recur(num - 1) + recur(num - 5);
}

int main() 
{
	recur(99);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		cout << dp[num - 1] << '\n';
	}

	return 0;
}