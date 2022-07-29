#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init();
void check_group(int f);
void bfs(int r, int c);
bool inRange(int r, int c);

int n;
int max_floor = 0;
int ans = 0;

vector<vector<int>> m;
vector<vector<int>> used;

void init() {
	cin >> n;
	m = vector<vector<int>>(n, vector<int>(n, 0));

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cin >> m[r][c];
			if (max_floor < m[r][c]) max_floor = m[r][c];
		}
	}
}

void check_group(int f) {
	int cnt = 0;
	used = vector<vector<int>>(n, vector<int>(n, 0));
	
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (m[r][c] <= f) used[r][c] = 1;
		}
	}

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (used[r][c]) continue;
			bfs(r, c);
			cnt++;
		}
	}

	if (cnt > ans) ans = cnt;
}

void bfs(int r, int c) {
	int dr[] = {-1,1,0,0};
	int dc[] = {0,0,-1,1};

	queue<pair<int, int>> q;
	q.push({r,c});
	used[r][c] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.first + dr[i];
			int nc = now.second + dc[i];
			if (!inRange(nr, nc) || used[nr][nc]) continue;
			q.push({nr, nc});
			used[nr][nc] = 1;
		}
	}
}

bool inRange(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
	
	init();
	for (int i = 0; i <= max_floor; i++) {
		check_group(i);
	}
	cout << ans;

	return 0;
}