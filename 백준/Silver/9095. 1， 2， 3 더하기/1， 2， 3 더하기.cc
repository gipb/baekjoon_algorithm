#include<iostream>
using namespace std;

int dp[11] = {};

int run(int n) {
	if (dp[n]) return dp[n];
	return dp[n] = run(n - 1) + run(n - 2) + run(n - 3);
}

int main() {
	int T;
	cin >> T;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	dp[10] = run(11);

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		cout << dp[num-1] << '\n';
	}

	return 0;
}