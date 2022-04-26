#include <iostream>
#include <vector>
using namespace std;

void init();
void spring();
void summer();
void fall();
void winter();

int N; // 땅 크기 결정
int M; // 초기 나무 개수
int K; // K 년 버티기

struct Tree {
	int age;
	int alive;
};

vector<vector<int>> ground;			// 양분 정보
vector<vector<int>> A;				// S2D2 양분 공급 정보
vector<vector<vector<Tree>>> tree;	// 나무 정보

// 인접 방향 배열
int dr[] = { -1,-1,-1,0,0,1,1,1 };
int dc[] = { -1,0,1,-1,1,-1,0,1 };

void init() {
	
	cin >> N >> M >> K;

	ground = vector<vector<int>>(N, vector<int>(N, 5));
	A = vector<vector<int>>(N, vector<int>(N, 0));
	tree = vector<vector<vector<Tree>>>(N, vector<vector<Tree>>(N, vector<Tree>()));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> A[r][c];
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		tree[r - 1][c - 1].push_back({ age, 1 });
	}

}

void spring() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int tree_cnt = tree[r][c].size();
			for (int i = 0; i < tree_cnt; i++) {
				if (ground[r][c] < tree[r][c][i].age) {
					tree[r][c][i].alive = 0;
				}
				else {
					ground[r][c] -= tree[r][c][i].age++;
				}
			}
		}
	}
}

void summer() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int tree_cnt = tree[r][c].size();
			for (int i = tree_cnt-1; i >= 0; i--) {
				if (tree[r][c].back().alive) break;
				ground[r][c] += tree[r][c].back().age / 2;
				tree[r][c].pop_back();
			}
		}
	}
}

void fall() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int tree_cnt = tree[r][c].size();
			for (int i = 0; i < tree_cnt; i++) {
				if (tree[r][c][i].age % 5 == 0) {
					for (int j = 0; j < 8; j++) {
						int nr = r + dr[j];
						int nc = c + dc[j];
						if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
						tree[nr][nc].insert(tree[nr][nc].begin(), { 1,1 });
					}
				}
			}
		}
	}
}

void winter() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			ground[r][c] += A[r][c];
		}
	}
}

int main() {

	init();
	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	int ans = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			ans += tree[r][c].size();
		}
	}

	cout << ans;

	return 0;
}