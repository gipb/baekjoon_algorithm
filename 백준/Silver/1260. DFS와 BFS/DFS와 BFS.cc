#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int>> MAP;
vector<int> used;
vector<int> path;

void dfs(int now) {
	path.push_back(now+1);
	used[now] = 1;
	for (int i = 0; i < N; i++) {
		if (!MAP[now][i] || used[i]) continue;
		dfs(i);
	}
}

void bfs(int num) {
	queue<int> q;
	q.push(num);
	used[num] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		path.push_back(now + 1);

		for (int i = 0; i < N; i++) {
			if (!MAP[now][i] || used[i]) continue;
			q.push(i);
			used[i] = 1;
		}
	}
}

int main() {

	cin >> N >> M >> V;
	MAP = vector<vector<int>>(N, vector<int>(N, 0));
	used = vector<int>(N, 0);
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		MAP[a-1][b-1] = MAP[b-1][a-1] = 1;
	}

	dfs(V-1);

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << ' ';
	}
	cout << '\n';

	used = vector<int>(N, 0);
	path.clear();

	bfs(V - 1);

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << ' ';
	}

	return 0;
}