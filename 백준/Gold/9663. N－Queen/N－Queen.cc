#include <iostream>
#include <vector>
#include <map>
using namespace std;

void init();
void dfs(int level);
bool isValid(int r, int c);
void check(int r, int c, int flag);

vector<vector<int>> board;

map<int, int> check_r; // 행 체크
map<int, int> check_c; // 열 체크
map<int, int> check_drb; // 오른쪽 아래 방향 대각선 체크
map<int, int> check_drt; // 오른쪽 위 방향 대각선 체크

int N;
int ans;

void init() {
	cin >> N;
	board = vector<vector<int>>(N, vector<int>(N,0));
	ans = 0;
}

void dfs(int level) {
	if (level == N) {
		ans++;
		return;
	}
	for (int c = 0; c < N; c++) {
		if (!isValid(level , c)) continue;
		check(level, c, 1);
		dfs(level + 1);
		check(level, c, 0);
	}
}

bool isValid(int r, int c) {
	if (check_r[r] || check_c[c] ||
		check_drb[r - c] || check_drt[r + c]) return false;
	return true;
}

void check(int r, int c, int flag) {
	check_r[r] = flag;
	check_c[c] = flag;
	check_drb[r - c] = flag;
	check_drt[r + c] = flag;
}

int main() {
	init();
	
	dfs(0);

	cout << ans;
	return 0;
}