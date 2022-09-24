#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> path;

void dfs(int level) {
	if (level == m) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int start = 1;
	if (level) start = path[level - 1];

	for (int i = start; i <= n; i++) {
		path.push_back(i);
		dfs(level + 1);
		path.pop_back();
	}
}

int main() {
	cin >> n >> m;

	dfs(0);

	return 0;
}