#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
	int r;
	int c;
};

void init();
void bfs_norm(bool isNorm);
bool inGrid(int r, int c);
bool isGroup(int r, int c, char color, bool isRG);

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int N; // 그리드 크기
vector<vector<char>> grid; // 색 저장
vector<vector<int>> used; // 탐색 여부 확인

int ans_norm; // 일반인 구역 수
int ans_gr;   // 색약인 구역 수

void init() {
	cin >> N;

	grid = vector<vector<char>>(N, vector<char>(N));
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> grid[r][c];
		}
	}
}

void bfs_norm(bool isNorm) {

	used = vector<vector<int>>(N, vector<int>(N, 0));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (used[r][c]) continue;

			char color = grid[r][c];

			queue<Pos> q;
			q.push({r,c});
			used[r][c] = 1;
			while (!q.empty()) {
				Pos now = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nr = dr[i] + now.r;
					int nc = dc[i] + now.c;
					if (!inGrid(nr, nc) || used[nr][nc] || !isGroup(nr,nc,color,isNorm)) continue;
					q.push({nr, nc});
					used[nr][nc] = 1;
				}
			}
			if (isNorm) ans_norm++;
			else ans_gr++;
		}
	}
}

bool inGrid(int r, int c) {
	return r < N && r >= 0 && c < N && c >= 0;
}

bool isGroup(int r, int c, char color, bool isNorm) {
	if (color == 'B') {
		return grid[r][c] == 'B';
	}
	if (isNorm) {
		return grid[r][c] == color;
	}
	return grid[r][c] != 'B';
}

int main() {
	init();
	bfs_norm(true);
	bfs_norm(false);

	cout << ans_norm << ' ' << ans_gr;
	return 0;
}