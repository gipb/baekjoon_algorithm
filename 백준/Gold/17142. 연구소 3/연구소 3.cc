#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init();
void dfs(int level, int prev);
void bfs();
int infect_check();

struct Pos {
	int r, c;
};

struct Info {
	int dist;
	Pos pos;
};

int N; // 연구소 크기
int M; // 활성 바이러스 갯수
int min_t = 21e8; // 최소 시간

// 상하좌우 방향배열
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

vector<vector<int>> MAP;	// 연구소 지도
vector<vector<int>> used;	// 체크 배열
vector<Pos> virus;			// 모든 바이러스 위치
vector<Pos> active;			// 활성화 되는 바이러스
vector<int> activated;		// 이미 활성화 된 바이러스

void init() {
	cin >> N >> M;

	MAP = vector<vector<int>>(N, vector<int>(N, 0));
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> MAP[r][c];
			if (MAP[r][c] == 2) virus.push_back({ r,c });
		}
	}

	activated = vector<int>(virus.size(), 0);

}

// 활성화 시킬 M개의 바이러스 정하기
void dfs(int level, int prev) {
	if (level == M) {
		// 정해질 때마다 최소 시간 확인
		bfs();
		return;
	}

	for (int i = prev; i < virus.size(); i++) {
		if (activated[i]) continue;
		active.push_back(virus[i]);
		activated[i] = 1;
		dfs(level + 1, i);
		activated[i] = 0;
		active.pop_back();
	}
}

void bfs() {

	// bfs 할 때마다 초기화
	used = vector<vector<int>>(N, vector<int>(N, 0));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (MAP[r][c] == 1) used[r][c] = 1;
		}
	}

	// 큐 초기화 및 기본 설정
	queue<Info> q;

	for (int i = 0; i < active.size(); i++) {
		Pos tar = active[i];
		q.push({ 0, tar });
		used[tar.r][tar.c] = 1;
	}

	int final_dist=0;	// 최종 걸린 시간
	int flag = 0;	// 전부 다 감염시켰을 경우 0
	
	while (!q.empty()) {
		Info now = q.front();
		q.pop();

		int dist = now.dist;
		int r = now.pos.r;
		int c = now.pos.c;

		if (dist > min_t) {
			flag = 1;
			break;
		}

		final_dist = dist;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (used[nr][nc]) continue;
			if (MAP[nr][nc] == 2) {
				if(infect_check()) continue;
			}
			q.push({ dist + 1, {nr,nc} });
			used[nr][nc] = 1;
		}
	}

	if (flag || infect_check() == 0) return;
	
	if (min_t > final_dist) min_t = final_dist;
}

int infect_check() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (!used[r][c]&&MAP[r][c]!=2) return 0;
		}
	}
	return 1;
}

int main() {
	
	init();

	dfs(0,0);
	
	if (min_t == 21e8) cout << -1;
	else cout << min_t;

	return 0;
}