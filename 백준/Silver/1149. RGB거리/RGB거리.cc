#include <iostream>
#include <vector>
using namespace std;

void init();
int dp_r(int num);
int dp_g(int num);
int dp_b(int num);

int min(int a, int b);

int N; // 집의 수
vector<vector<int>> cost;
vector<vector<int>> min_cost;

int ans = 0;

void init() {
	cin >> N;
	cost = vector<vector<int>>(N, vector<int>(3, 0));
	min_cost = vector<vector<int>>(N, vector<int>(3, 0));
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < 3; c++) {
			cin >> cost[r][c];
		}
	}
}

int dp_r(int num) {
	// 첫 번째 집일 경우
	if (num == 0) return min_cost[num][0] = cost[num][0];

	// 이미 확인한 값일 경우
	if (min_cost[num][0]) return min_cost[num][0];

	// 그 이상의 집일 경우
	return min_cost[num][0] = min(dp_g(num - 1), dp_b(num - 1)) + cost[num][0];
}

int dp_g(int num) {
	// 첫 번째 집일 경우
	if (num == 0) return min_cost[num][1] = cost[num][1];

	// 이미 확인한 값일 경우
	if (min_cost[num][1]) return min_cost[num][1];
	
	// 그 이상의 집일 경우
	return min_cost[num][1] = min(dp_r(num - 1), dp_b(num - 1)) + cost[num][1];
}

int dp_b(int num) {
	// 첫 번째 집일 경우
	if (num == 0) return min_cost[num][2] = cost[num][2];

	// 이미 확인한 값일 경우
	if (min_cost[num][2]) return min_cost[num][2];

	// 그 이상의 집일 경우
	return min_cost[num][2] = min(dp_g(num - 1), dp_r(num - 1)) + cost[num][2];
}

int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	init();
	ans = min(dp_r(N-1), min(dp_g(N-1), dp_b(N - 1)));
	cout << ans;
	return 0;
}