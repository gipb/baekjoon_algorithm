#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
	int x, y;
};

int main() 
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		int beer = 20;
		vector<Pos> conv;
		cin >> n;

		int hx, hy;
		cin >> hx >> hy;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			conv.push_back({ x,y });
		}

		vector<int> used(conv.size(), 0);

		int rx, ry;
		cin >> rx >> ry;

		int is_arrived = 0;

		queue<Pos> q;

		q.push({ hx, hy });

		while (!q.empty()) {
			Pos now = q.front();
			q.pop();
			int x = now.x;
			int y = now.y;

			if (abs(rx - x) + abs(ry - y) <= 1000) {
				cout << "happy\n";
				is_arrived = 1;
				break;
			}

			for (int i = 0; i < n; i++) {
				if (used[i]) continue;
				int nx = conv[i].x;
				int ny = conv[i].y;
				if (abs(nx - x) + abs(ny - y) > 1000) continue;
				q.push({ nx ,ny });
				used[i] = 1;
			}
		}
		if (!is_arrived) cout << "sad\n";

	}
	return 0;
}