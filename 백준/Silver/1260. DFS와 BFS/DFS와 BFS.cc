#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, v;

vector<vector<int>> MAP;
vector<int> used;

void dfs(int level, int node) {
	cout << node + 1 << ' ';
	if (level == n) return;

	for (int i = 0; i < n; i++) {
		if (!MAP[node][i] || used[i]) continue;
		used[i] = 1;
		dfs(level + 1, i);
	}
}


int main(){

	cin >> n >> m >> v;

	MAP = vector<vector<int>>(n, vector<int>(n, 0));
	used = vector<int>(n, 0);

	for (int i = 0; i < m; i++) {
		int r, c;
		cin >> r >> c;
		MAP[r - 1][c - 1] = 1;
		MAP[c - 1][r - 1] = 1;
	}

	// dfs
	used[v - 1] = 1;
	dfs(0, v - 1);
	cout << endl;

	used = vector<int>(n, 0);

	// bfs
	queue<int> q;
	q.push(v - 1);
	used[v - 1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now + 1 << ' ';
		for (int i = 0; i < n; i++) {
			if (!MAP[now][i] || used[i]) continue;
			q.push(i);
			used[i] = 1;
		}
	}

	return 0;
}