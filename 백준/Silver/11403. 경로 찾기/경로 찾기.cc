#include <iostream>
#include <vector>
using namespace std;

void init();
void update_answer();
bool isChanged();

int N; // node 개수
vector<vector<int>> MAP;
vector<vector<int>> answer;
vector<vector<int>> prev_answer;

void init() {
	cin >> N;

	MAP = vector<vector<int>>(N, vector<int>(N, 0));
	answer = vector<vector<int>>(N, vector<int>(N, 0));
	prev_answer = vector<vector<int>>(N, vector<int>(N, 0));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> MAP[r][c];
			// 간선이 존재하면 갈 수 있다.
			answer[r][c] = MAP[r][c];
		}
	}
}

void update_answer() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			prev_answer[r][c] = answer[r][c];
		}
	}
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (!answer[r][c]) continue;
			for (int t = 0; t < N; t++) {
				answer[r][t] |= answer[c][t];
			}
		}
	}
}

bool isChanged() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (answer[r][c] != prev_answer[r][c]) return true;
		}
	}
	return false;
}

void print_answer() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << answer[r][c];
			if (c < N - 1) cout << ' ';
		}
		cout << '\n';
	}
}

int main() {
	init();
	while (true) {
		if (!isChanged()) break;
		update_answer();
	}
	print_answer();
	return 0;
}