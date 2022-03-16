#include<iostream>
using namespace std;

int N, M;

int cnt_color(char board[2][8][9], char** arr, int y, int x) {
	int cnt[2] = {};
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (arr[y + i][x + j] != board[k][i][j]) cnt[k]++;
			}
		}
	}
	if (cnt[0] > cnt[1]) return cnt[1];
	else return cnt[0];
}

int main() {
	char board[2][8][9] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
	};
	cin >> N >> M;
	char** arr = new char*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new char[M+1];
	}
	for (int y = 0; y < N; y++) {
		cin >> arr[y];
	}
	int min = cnt_color(board, arr, 0, 0);
	for (int y = 0; y < N-7; y++) {
		for (int x = 0; x < M-7; x++) {
			int cnt = cnt_color(board, arr, y, x);
			if (min > cnt) min = cnt;
		}
	}

	cout << min;

	return 0;
}