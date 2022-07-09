#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Pos {
	int r, c;
};

int n;
vector<string> MAP;
vector<vector<int>> used;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

bool inRange(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}

int bfs(int r, int c) {
	queue<Pos> q;
	q.push({ r,c });
	used[r][c] = 1;

	int ret = 0;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		ret++;

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			if (!inRange(nr, nc) || used[nr][nc]) continue;
			if (MAP[nr][nc] == '0') continue;
			q.push({ nr, nc });
			used[nr][nc] = 1;
		}
	}

	return ret;
}

int main(){
	cin >> n;
	used = vector<vector<int>>(n, vector<int>(n, 0));

	vector<int> answer;

	for (int i = 0; i < n; i++) {
		string txt;
		cin >> txt;
		MAP.push_back(txt);
	}

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (MAP[r][c] == '0' || used[r][c]) continue;
			int group = bfs(r, c);
			answer.push_back(group);
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}