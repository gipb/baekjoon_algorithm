#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos {
	int r, c;
};

int N;	// 지도 크기

vector<vector<int>> MAP;	// 지도
vector<vector<int>> used;	// 체크 배열
vector<int> group;			// 그룹 단지 수 추가용 배열

// 방향 배열
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(Pos start) {
	
	int cnt = 0;
	queue<Pos> q;

	q.push(start);
	used[start.r][start.c] = 1;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		
		cnt++;
		int r = now.r;
		int c = now.c;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (!MAP[nr][nc] || used[nr][nc]) continue;

			q.push({ nr,nc });
			used[nr][nc] = 1;
		}

	}

	group.push_back(cnt);

}

int main() {

	cin >> N;

	MAP = vector<vector<int>>(N, vector<int>(N, 0));
	used = vector<vector<int>>(N, vector<int>(N, 0));

	for (int r = 0; r < N; r++) {
		string txt;
		cin >> txt;
		for (int c = 0; c < N; c++) {
			int num = txt[c] - '0';
			MAP[r][c] = num;
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (!MAP[r][c] || used[r][c]) continue;
			bfs({r,c});
		}
	}

	sort(group.begin(), group.end());

	cout << group.size()<<'\n';
	for (int i = 0; i < group.size(); i++) {
		cout << group[i] << '\n';
	}

	return 0;
}