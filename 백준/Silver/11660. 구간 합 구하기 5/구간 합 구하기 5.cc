#include <iostream>
#include <vector>
using namespace std;

void init();

vector<vector<long long>> MAP;

int N;
int M;

void init() {
	cin >> N >> M;

	MAP = vector<vector<long long>>(N+1, vector<long long>(N+1, 0));



	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int num;
			cin >> num;
			MAP[r][c] = MAP[r - 1][c] + MAP[r][c - 1] - MAP[r - 1][c - 1] + num;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		long long ans = MAP[x2][y2] - MAP[x2][y1 - 1] - MAP[x1 - 1][y2] + MAP[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}
	return 0;
}