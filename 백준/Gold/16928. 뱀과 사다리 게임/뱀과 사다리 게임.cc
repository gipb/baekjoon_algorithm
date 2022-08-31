#include <iostream>
#include <map>
#include <queue>
using namespace std;

void init();
void bfs();

int N; // 사다리
int M; // 뱀

map<int, int> ladder;
map<int, int> snake;

int MAP[101] = {};

struct cmp {
	bool operator() (int left, int right) {
		return MAP[left] > MAP[right];
	}
};

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		snake[u] = v;
	}
}

void bfs() {
	priority_queue<int,vector<int>,cmp> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.top();
		q.pop();

		if (now == 100) return;

		if (ladder[now]) {
			MAP[ladder[now]] = MAP[now];
			q.push(ladder[now]);

		}
		else if (snake[now]) {
			MAP[snake[now]] = MAP[now];
			q.push(snake[now]);
		}
		else {
			for (int i = 1; i < 7; i++) {
				if (MAP[now + i]) continue;
				if (now + i > 100) break;
				MAP[now + i] = MAP[now] + 1;
				q.push(now + i);
			}
		}
	}
}

int main() {
	init();
	bfs();
	cout << MAP[100];
	return 0;
}