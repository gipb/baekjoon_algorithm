#include <iostream>
#include <vector>
using namespace std;

void init();

vector<int> arr;
vector<int> dp;

int N;

void init() {
	cin >> N;
	arr = vector<int>(N, 0);
	int MAX = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > MAX) MAX = arr[i];
	}
	dp = vector<int>(MAX + 1, 0);
}

int main() {
	init();
	int ans = 0;

	for (int i = 0; i < N; i++) {
		int tar = arr[i];
		int MAX = 0;
		for (int j = 0; j < tar; j++) {
			if (dp[j] > MAX) MAX = dp[j];
		}
		dp[tar] = MAX + 1;
	}

	for (int i = 0; i < dp.size(); i++) {
		if (ans < dp[i]) ans = dp[i];
	}

	cout << ans;
	return 0;
}