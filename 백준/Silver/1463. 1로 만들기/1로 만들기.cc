#include <iostream>
using namespace std;

#define MAX_VALUE 1000001

int dp[MAX_VALUE] = {};

int find_min(int a, int b, int c) {
	return a > b ? (b > c ? c : b) : (a > c ? c : a);
}

int recur(int X) {
	if (dp[X]) return dp[X];
	if (X < 1) return dp[X] = MAX_VALUE;
	if (X == 1) return dp[X] = 0;
	if (X == 2) return dp[X] = 1;
	if (X == 3) return dp[X] = 1;
	int a = recur(X - 1);
	int b = X % 3 == 0 ? recur(X / 3) : MAX_VALUE;
	int c = X % 2 == 0 ? recur(X / 2) : MAX_VALUE;

	return dp[X] = find_min(a,b,c) + 1;
}

int main() {

	int X;
	cin >> X;
	
	int ans = recur(X);
	cout << ans;

	return 0;
}