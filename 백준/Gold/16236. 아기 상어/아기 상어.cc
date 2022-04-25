#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Info {
	int dist;
	int r, c;
};

void bfs();
bool cmp(Info left, Info right);

vector<vector<int>> MAP;	// 공간
vector<vector<int>> used;	// bfs를 위한 체크용 배열

int N;				// 공간의 크기, N x N
int sr, sc;			// 상어의 현 위치
int shark_size = 2;	// 상어의 현 크기
int eat_cnt = 0;	// 상어가 먹은 물고기 수
int ans = 0;		// 걸린 시간
int flag = 0;		// 더 이상 확인할 필요가 없을 때


void bfs() {
	queue<Info> q;

	// 체크 배열 초기화
	used = vector<vector<int>>(N, vector<int>(N, 0));

	q.push({ 0, sr, sc });
	used[sr][sc] = 1;

	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };

	// 가장 가까운 거리에 있는 고기 찾기 위한 변수
	int min_dist = 50;

	// 가장 가까운 거리에 있는 고기가 여러 개일 경우 기록 위한 벡터
	vector<Info> valid_fish;

	while (!q.empty()) {
		Info now = q.front();
		q.pop();

		int r = now.r;
		int c = now.c;
		int dist = now.dist;

		// 상어 몸집보다 작은 물고기만 먹는 것이 가능
		if (MAP[r][c] > 0 && MAP[r][c] < 9 && MAP[r][c] < shark_size) {
			if (min_dist == 50) min_dist = dist;
			else if (dist > min_dist) break;
			valid_fish.push_back(now);
		}

		// 최소 거리 찾기 위한 queue 업데이트
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (MAP[nr][nc] > shark_size || used[nr][nc]) continue;
			q.push({ dist + 1, nr, nc });
			used[nr][nc] = 1;
		}
	}
	
	// 끝까지 다 확인해도 먹을 물고기가 없다.
	if (valid_fish.size() == 0) {
		flag = 1;
		return;
	}

	// 먹을 수 있는 물고기가 여러 개일 경우 판단 필요
	if(valid_fish.size()>1)
		sort(valid_fish.begin(), valid_fish.end(), cmp);

	Info next = valid_fish.front();

	// 먹은 후 상어의 위치 변경, 먹은 물고기 없애기, 먹은 횟수 올리기, 시간 추가
	sr = next.r;
	sc = next.c;
	MAP[sr][sc] = 0;
	eat_cnt++;
	ans += next.dist;

	// 몸집 크기만큼 먹었을 때 몸집 키우기
	if (eat_cnt == shark_size) {
		shark_size++;
		eat_cnt = 0;
	}
}

bool cmp(Info left, Info right) {
	return left.r == right.r ? left.c < right.c : left.r < right.r;
}

int main() {

	cin >> N;
	
	MAP = vector<vector<int>>(N, vector<int>(N, 0));
	

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> MAP[r][c];
			if (MAP[r][c] == 9) {
				sr = r;
				sc = c;
				MAP[r][c] = 0;
			}
		}
	}

	while (true) {
		bfs();
		if (flag) break;
	}

	cout << ans;

	return 0;
}