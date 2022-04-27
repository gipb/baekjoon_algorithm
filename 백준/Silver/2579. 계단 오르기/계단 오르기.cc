#include <iostream>
#include <vector>
using namespace std;

struct Info {
	int canOne;
	int onlyTwo;
};

vector<int> scores;
vector<Info> dp;

Info recur(int n) {
	if (dp[n].canOne || dp[n].onlyTwo) return dp[n];
	if (n == 0) return dp[n] = { scores[0],0};
	if (n == 1) return dp[n] = { scores[1],scores[0]+scores[1]};

	Info forCheck = recur(n - 2);

	int canOne = forCheck.canOne > forCheck.onlyTwo ? forCheck.canOne : forCheck.onlyTwo;
	canOne += scores[n];

	return dp[n] = { canOne, recur(n - 1).canOne + scores[n] };
}

int main() {

	int N;
	cin >> N;
	dp = vector<Info>(N, { 0,0 });
	for (int i = 0; i < N; i++) {
		int score;
		cin >> score;
		scores.push_back(score);
	}

	Info ans = recur(N-1);

	int ret = ans.canOne > ans.onlyTwo ? ans.canOne : ans.onlyTwo;

	cout << ret;

	return 0;
}