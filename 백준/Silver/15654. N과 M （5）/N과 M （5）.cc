#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<int> num;
vector<int> path;
vector<int> used;

void dfs(int level) {
	if (level == m) {
		for (int i = 0; i < path.size(); i++) {
			cout << num[path[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		path.push_back(i);
		used[i] = 1;
		dfs(level + 1);
		path.pop_back();
		used[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}

	used = vector<int>(n, 0);
	sort(num.begin(), num.end());

	dfs(0);

	return 0;
}