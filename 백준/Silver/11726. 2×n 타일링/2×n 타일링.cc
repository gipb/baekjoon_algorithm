#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dp;

int recur(int n) {
	if (n == 1) return dp[n] = 1;
	if (n == 2) return dp[n] = 2;
	if (dp[n]) return dp[n];

	return dp[n] = (recur(n - 1) + recur(n - 2))%10007;
}

int main() {

	cin >> N;
	dp = vector<int>(N + 1, 0);

	int ans = recur(N);

	cout << ans;

	return 0;
}