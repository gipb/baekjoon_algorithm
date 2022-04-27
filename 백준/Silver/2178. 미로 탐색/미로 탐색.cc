#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int dist;
	int r, c;
};

int main() {
	
	int N, M;
	cin >> N >> M;

	vector<vector<int>> MAP(N, vector<int>(M, 0));
	vector<vector<int>> used(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		string txt;
		cin >> txt;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = txt[j] - '0';
		}
	}

	// 방향 배열
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };

	int ans = 0;

	// bfs 활용
	queue<Info> q;

	q.push({ 1,0,0 });
	used[0][0] = 1;

	while (!q.empty()) {
		Info now = q.front();
		q.pop();
		
		int r = now.r;
		int c = now.c;
		int dist = now.dist;

		if (r == N - 1 && c == M - 1) {
			ans = dist;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (!MAP[nr][nc] || used[nr][nc]) continue;
			q.push({ dist + 1, nr, nc });
			used[nr][nc] = 1;
		}
	}

	cout << ans;

	return 0;
}