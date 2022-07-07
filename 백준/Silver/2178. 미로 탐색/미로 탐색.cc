#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Info {
	int r, c;
	int cnt;
};

int n, m;

vector<string> MAP;
vector<vector<int>> used;

bool inRange(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < m;
}

bool isValid(int r, int c) {
	return MAP[r][c] == '1';
}

int main(){

	cin >> n >> m;

	used = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		MAP.push_back(s);
	}
	
	// 방향배열
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };

	queue<Info> q;
	q.push({ 0,0,1 });
	used[0][0] = 1;

	while (!q.empty()) {
		Info now = q.front();
		q.pop();


		if (now.r == n - 1 && now.c == m - 1) {
			cout << now.cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			if (!inRange(nr, nc) || used[nr][nc]) continue;
			if (!isValid(nr, nc)) continue;
			q.push({ nr,nc , now.cnt+1});
			used[nr][nc] = 1;
		}
	}

	return 0;
}