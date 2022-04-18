#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> MAP;
int N, M, H;
int ans = 4;

// 사다리 체크
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
	// 성공할 경우 ans에 추가된 사다리 개수 등록
	if (!check()) {
		if (ans > level) ans = level;
		return;
	}

	for (int r = 1; r <= H; r++) {
		for (int c = 1; c < N; c++) {
			// dfs 실행 도중 성공한 분기가 있다면 return
			if (level >= ans) return;
			
			// 사다리를 놓을 수 없는 경우 배제
			if (MAP[r][c] || MAP[r][c+1]) continue;
			
			// 새로운 사다리 놓기
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
	
	// 최소한 각 가로줄은 세로줄 사이에서 짝수 개로 연결되어야 함.
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

	// 추가 연결이 필요한 사다리 갯수 확인
	for (int i = 1; i <= N; i++) {
		if (dat[i] % 2) odd_cnt++;
	}
	
	// 추가되어야 하는 사다리의 최소 갯수가 4개 이상인 것들은 배제
	if(odd_cnt<=3)
		dfs(0);

	if (ans == 4) ans = -1;
	cout << ans;

	return 0;
}
