#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> MAP;
int N, M, H;
int ans = 4;

int check() {
	for (int c = 1; c <= N; c++) {
		int cur_c = c;
		for (int r = 1; r <= H; r++) {
			if (MAP[r][cur_c]) cur_c = MAP[r][cur_c];
		}
		if (cur_c != c) return 1;
	}
	return 0;
}

void dfs(int level) {
	if (level >= ans) return;
	if (!check()) {
		if (ans > level) ans = level;
		return;
	}

	for (int r = 1; r <= H; r++) {
		for (int c = 1; c < N; c++) {
			if (level >= ans) return;
			if (MAP[r][c] || MAP[r][c+1]) continue;
			MAP[r][c] = c + 1;
			MAP[r][c + 1] = c;
			dfs(level + 1);
			MAP[r][c] = 0;
			MAP[r][c + 1] = 0;
		}
	}
}

int main()
{	
	cin >> N >> M >> H;

	MAP = vector<vector<int>>(H+1, vector<int>(N+1, 0));
	vector<int> dat(N + 1, 0);

	int odd_cnt = 0;

	for (int m = 0; m < M; m++) {

		int a, b;
		cin >> a >> b;
		
		// b번 라인의 a 위치에서 b+1번 라인으로 간다고 표시
		MAP[a][b] = b+1;
		dat[b]++;
		// b+1번 라인의 a 위치에서 b번 라인으로 간다고 표시
		MAP[a][b+1] = b;
	}

	for (int i = 1; i <= N; i++) {
		if (dat[i] % 2) odd_cnt++;
	}

	if(odd_cnt<=3)
		dfs(0);

	if (ans == 4) ans = -1;
	cout << ans;

	return 0;
}