#include<iostream>
#include<vector>
using namespace std;

vector<vector<double>> MAP;
vector<int> used;
int N;
double ans;
double p;

void init() {
	N = 0;
	ans = 0;
	p = 1;
	cin >> N;
	MAP = vector<vector<double>>(N, vector<double>(N, 0));
	used = vector<int>(N, 0);

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			double num;
			cin >> num;
			MAP[r][c] = num / 100;
		}
	}
}

void recur(int level, double p=1) {
	if (p==0) return;
	if (p < ans) return;
	if (level == N) {
		if (ans < p) ans = p;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		used[i] = 1;
		recur(level + 1, p*MAP[level][i]);
		used[i] = 0;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		init();
		recur(0);
		printf("#%d %.6f\n", t, ans*100);
	}

	return 0;
}