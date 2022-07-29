#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init();
int check_group();
void bfs(int r, int c);
void change_glacier();
bool inRange(int r, int c);

int n, m;
int max_h=0;
int ans = 0;

vector<vector<int>> g;
vector<vector<int>> used;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

void init() {
	cin >> n >> m;
	
	g = vector<vector<int>>(n, vector<int>(m, 0));
	
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			cin >> g[r][c];
			if (g[r][c] > max_h) max_h = g[r][c];
		}
	}

}

int check_group() {
	int cnt = 0;
	used = vector<vector<int>>(n, vector<int>(m, 0));

	for (int r = 1; r < n-1; r++) {
		for (int c = 1; c < m-1; c++) {
			if (used[r][c] || !g[r][c]) continue;
			bfs(r, c);
			cnt++;
			if (cnt > 1) return cnt;
		}
	}
	return cnt;
}

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({r,c});
	used[r][c] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.first + dr[i];
			int nc = now.second + dc[i];
			if (used[nr][nc] || !g[nr][nc])continue;
			q.push({nr,nc});
			used[nr][nc] = 1;
		}
	}
}

void change_glacier() {
	vector<vector<int>> change(n, vector<int>(m, 0));

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (!g[r][c]) continue;
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (!inRange(nr, nc) || g[nr][nc]) continue;
				change[r][c]++;
			}
		}
	}

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (!g[r][c]) continue;
			g[r][c] -= change[r][c];
			if (g[r][c] < 0) g[r][c] = 0;
		}
	}
}

bool inRange(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

int main() {
	
	init();
	int flag = 1;
	int cnt = 0;
	while (flag==1){
		flag = check_group();
		change_glacier();
		cnt++;
	}

	if (!flag) ans = 0;
	else ans = cnt - 1;
	cout << ans;

	return 0;
}