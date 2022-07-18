#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int person;
	int cnt;
};

int n, m; // 사람, 관계
int tar1, tar2; // 촌수 계산해야할 사람
vector<vector<int>> f_map;
vector<int> used;

int ans = -1;

int main(){
	cin >> n;
	f_map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	used = vector<int>(n + 1, 0);
	cin >> tar1 >> tar2;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		f_map[x][y] = f_map[y][x] = 1;
	}

	queue<Info> q;
	for (int i = 0; i < n + 1; i++) {
		if (!f_map[tar1][i]) continue;
		q.push({ i,1 });
		used[i] = 1;
	}
	used[tar1] = 1;

	while (!q.empty()) {
		Info now = q.front();
		q.pop();

		if (now.person == tar2) {
			ans = now.cnt;
			break;
		}

		for (int i = 0; i < n + 1; i++) {
			if (!f_map[now.person][i] || used[i]) continue;
			q.push({ i, now.cnt + 1 });
			used[i] = 1;
		}
	}

	cout << ans;

	return 0;
}