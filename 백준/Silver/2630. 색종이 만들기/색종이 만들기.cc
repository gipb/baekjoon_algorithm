#include <iostream>
#include <vector>
using namespace std;

int N; // 색종이 한 변 길이

vector<vector<int>> paper;	// 색종이 정보 저장 배열
int ans[2] = {};			// 정답 저장 배열

// 입력 받고 initializing
void init() {

	cin >> N;
	paper = vector<vector<int>>(N, vector<int>(N, 0));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> paper[r][c];
		}
	}

}

// 해당 부분이 사용 가능한 색종이인지 확인
int check_valid(int l, int y, int x) {
	int color = paper[y][x];
	for (int r = y; r < y + l; r++) {
		for (int c = x; c < x + l; c++) {
			if (paper[r][c] != color) return 0;
		}
	}

	return 1;
}

// dfs를 활용하여 잘라진 색종이 찾기
void find_div(int len, int r, int c) {

	if (check_valid(len, r, c)) {
		ans[paper[r][c]]++;
		return;
	}

	int nlen = len / 2;

	find_div(nlen, r, c);
	find_div(nlen, r + nlen, c);
	find_div(nlen, r, c + nlen);
	find_div(nlen, r + nlen, c + nlen);
}

int main() {

	init();
	find_div(N, 0 ,0);

	cout << ans[0] << '\n' << ans[1];

	return 0;
}