#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int time;
	int r, c;
};

int main() {

	int N, M;
	cin >> M >> N;

	// 박스 배열, 체크 배열 초기화
	vector<vector<int>> box(N, vector<int>(M,0));
	vector<vector<int>> used(N, vector<int>(M,0));

	// bfs에 쓰일 queue 생성
	queue<Info> q;
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> box[r][c];
			if (box[r][c] == -1) used[r][c] = 1;
			if (box[r][c] == 1) {
				q.push({ 0,r,c });
				used[r][c] = 1;
			}
		}
	}

	// 정답 저장 변수
	int ans = 0;

	// 방향 배열
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };

	while (!q.empty()) {
		Info now = q.front();
		q.pop();

		int r = now.r;
		int c = now.c;
		int t = now.time;

		ans = t;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (used[nr][nc]) continue;
			q.push({ t + 1,nr,nc });
			used[nr][nc] = 1;
		}
	}

	int flag = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (!used[r][c]) {
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}

	if (flag) cout << -1;
	else cout << ans;

	return 0;
}