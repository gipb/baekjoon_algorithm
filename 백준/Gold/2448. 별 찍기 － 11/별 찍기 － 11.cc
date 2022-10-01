#include <iostream>
#include <vector>
using namespace std;

void init();
void recur(int n, int r, int c);

int N; // row
int M; // column
vector<vector<int>> MAP;

void init() {
	cin >> N;
	M = 2 * N - 1;
	MAP = vector<vector<int>>(N, vector<int>(M, 0));
}

void recur(int n, int r, int c) {
	if (n == 3) {
		for (int dr = 0; dr < 3; dr++) {
			for (int dc = 0; dc < 5; dc++) {
				if ((dc % (3 - dr)) == (2 - dr)) {
					MAP[r + dr][c + dc] = 1;
				}
			}
		}
	}
	else {
		n /= 2;
		recur(n, r, c + n);
		recur(n, r + n, c);
		recur(n, r + n, c + 2 * n);
	}
}

int main() {
	init();

	recur(N, 0, 0);

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			char ans = MAP[r][c]==1 ? '*' : ' ';
			cout << ans;
		}
		cout << '\n';
	}

	return 0;
}