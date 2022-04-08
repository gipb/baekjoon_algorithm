#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Pos {
	int r, c;
};

int main()
{
	int dr[] = { 1,-1,0,0 };
	int dc[] = { 0,0,1,-1 };

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M, K;
		cin >> M >> N >> K;
		vector<vector<int>> MAP(N, vector<int>(M, 0));

		for (int i = 0; i < K; i++) {
			int r, c;
			cin >> c >> r;
			MAP[r][c] = 1;
		}

		int cnt = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (!MAP[r][c]) continue;
				cnt++;
				queue<Pos> q;
				q.push({ r,c });
				MAP[r][c] = 0;
				while (!q.empty()) {
					Pos now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nr = now.r + dr[i];
						int nc = now.c + dc[i];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
						if (!MAP[nr][nc]) continue;
						q.push({ nr, nc });
						MAP[nr][nc] = 0;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}