#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>> MAP;

struct Pos {
	int r, c;
};

int one_by_four(int r, int c) {
	if (c > M - 4) return 0;
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		ret += MAP[r][c + i];
	}
	return ret;
}

int four_by_one(int r, int c) {
	if (r > N - 4) return 0;
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		ret += MAP[r + i][c];
	}
	return ret;
}

int two_by_two(int r, int c) {
	if (r > N - 2 || c > M - 2) return 0;
	int ret = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ret += MAP[r + i][c + j];
		}
	}
	return ret;
}

int two_by_three(int r, int c) {
	if (r > N - 2 || c > M - 3) return 0;
	int ret = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			ret += MAP[r + i][c + j];
		}
	}

	Pos del[8][2] = {
		{{0,0}, {0,1}},
		{{0,0}, {0,2}},
		{{0,0}, {1,2}},
		{{1,0}, {1,1}},
		{{1,0}, {1,2}},
		{{1,0}, {0,2}},
		{{0,1}, {0,2}},
		{{1,1}, {1,2}}
	};

	int min = 2001;
	for (int i = 0; i < 8; i++) {
		int temp = MAP[r + del[i][0].r][c + del[i][0].c] +
			MAP[r + del[i][1].r][c + del[i][1].c];
		if (min > temp) min = temp;
	}

	return ret - min;
}

int three_by_two(int r, int c) {
	if (r > N - 3 || c > M - 2) return 0;
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			ret += MAP[r + i][c + j];
		}
	}

	Pos del[8][2] = {
		{{0,0}, {1,0}},
		{{0,0}, {2,0}},
		{{0,0}, {2,1}},
		{{0,1}, {1,1}},
		{{0,1}, {2,1}},
		{{0,1}, {2,0}},
		{{1,0}, {2,0}},
		{{1,1}, {2,1}}
	};

	int min = 2001;
	for (int i = 0; i < 8; i++) {
		int temp = MAP[r + del[i][0].r][c + del[i][0].c] +
			MAP[r + del[i][1].r][c + del[i][1].c];
		if (min > temp) min = temp;
	}

	return ret - min;
}

int main()
{	
	
	cin >> N >> M;
	MAP = vector<vector<int>>(N, vector<int>(M, 0));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> MAP[r][c];
		}
	}

	int max_value = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			int obf = one_by_four(r, c);
			int fbo = four_by_one(r, c);
			int tbt = two_by_two(r, c);
			int tbth = two_by_three(r, c);
			int thbt = three_by_two(r, c);
			max_value = max(obf, max(fbo, max(tbt, max(tbth, max(thbt, max_value)))));
		}
	}

	cout << max_value;

	return 0;
}