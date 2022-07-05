#include <iostream>
#include <vector>
using namespace std;

void split_dfs(int r, int c, int s);
void dfs(int r, int c, int s);

vector<vector<int>> p;

int ans[3] = { 0,0,0 };

void split_dfs(int r, int c, int s) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			dfs(r + (y * s / 3), c + (x * s / 3), s / 3);
		}
	}
}

void dfs(int r, int c, int s) {
	int now = p[r][c];

	for (int y = 0; y < s; y++) {
		for (int x = 0; x < s; x++) {
			if (p[r + y][c + x] != now) {
				split_dfs(r, c, s);
				return;
			}
		}
	}

	ans[now + 1]++;
}

int main() {
	int n;
	cin >> n;

	p = vector<vector<int>>(n, vector<int>(n, 0));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cin >> p[r][c];
		}
	}

	dfs(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}