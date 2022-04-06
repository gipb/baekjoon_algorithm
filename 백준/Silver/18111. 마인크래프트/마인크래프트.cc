#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> land;
int N, M, B;
int sum = 0;

int calc_time(int layer) {
	int flag = (sum + B) < layer * N * M;
	if (flag) return 21e8;
	int time = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			time += (land[r][c] > layer ? (land[r][c] - layer) * 2 : (layer - land[r][c]));
		}
	}
	return time;
}

int main() {
	cin >> N >> M >> B;
	land = vector<vector<int>>(N, vector<int>(M, 0));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> land[r][c];
			sum += land[r][c];
		}
	}

	int min_layer = 257;
	int max_layer = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (land[r][c] > max_layer) max_layer = land[r][c];
			if (land[r][c] < min_layer) min_layer = land[r][c];
		}
	}

	if (max_layer > 256) max_layer = 256;

	int min_time = 21e8;
	int ans_layer = 0;

	for (int layer = min_layer; layer <= max_layer; layer++) {
		int time = calc_time(layer);
		if (min_time > time) {
			min_time = time;
			ans_layer = layer;
		}
		else if (min_time == time && ans_layer < layer) {
			ans_layer = layer;
		}
	}

	cout << min_time << ' ' << ans_layer;

	return 0;
}