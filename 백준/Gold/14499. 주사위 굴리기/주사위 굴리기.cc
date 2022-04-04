#include <iostream>
#include <vector>
using namespace std;

#define BOTTOM dice[3][1]
#define TOP dice[1][1]
#define RIGHT dice[1][2]
#define LEFT dice[1][0]
#define UP dice[0][1]
#define DOWN dice[2][1]

int N, M;	// 세로 , 가로
int x, y;	// 가로 좌표, 세로 좌표
int K;		// 명령의 개수

vector<vector<int>> MAP;	// 지도
int dice_num[7] = {};		// 주사위 값
int dice[4][3] = {			// 주사위 상태
	0,2,0,
	4,1,3,
	0,5,0,
	0,6,0
};

// 동서북남 (1,2,3,4) 순서
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1, 0,0 };

void change(int dir) {
	int nx = x + dr[dir-1];
	int ny = y + dc[dir-1];
	if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;

	x = nx;
	y = ny;
	if (dir == 1) {
		int temp = BOTTOM;
		BOTTOM = RIGHT;
		RIGHT = TOP;
		TOP = LEFT;
		LEFT = temp;
	}
	else if (dir == 2) {
		int temp = BOTTOM;
		BOTTOM = LEFT;
		LEFT = TOP;
		TOP = RIGHT;
		RIGHT = temp;
	}
	else if (dir == 3) {
		int temp = BOTTOM;
		BOTTOM = UP;
		UP = TOP;
		TOP = DOWN;
		DOWN = temp;
	}
	else if (dir == 4) {
		int temp = BOTTOM;
		BOTTOM = DOWN;
		DOWN = TOP;
		TOP = UP;
		UP = temp;
	}

	if (MAP[x][y] == 0) {
		MAP[x][y] = dice_num[BOTTOM];
	}
	else {
		dice_num[BOTTOM] = MAP[x][y];
		MAP[x][y] = 0;
	}

	cout << dice_num[TOP] << '\n';
	return;
}

int main() {
	cin >> N >> M >> x >> y >> K;

	MAP = vector<vector<int>>(N, vector<int>(M, 0));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> MAP[r][c];
		}
	}

	for (int i = 0; i < K; i++) {
		int cmd;
		cin >> cmd;
		change(cmd);
	}

	return 0;
}