#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int floor;
	int cnt;
};

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	vector<int> floor(F, -1);
	queue<Info> q;

	floor[S - 1] = 0;

	q.push({ S - 1, 0 });

	while (!q.empty()) {
		Info now = q.front();
		q.pop();
		
		int nfu = now.floor + U;
		int nfd = now.floor - D;
		int nc = now.cnt+1;
		if (nfu < F && U>0 && floor[nfu] == -1) {
			floor[nfu] = nc;
			q.push({ nfu, nc });
		}
		if (nfd >= 0 && D > 0 && floor[nfd] == -1) {
			floor[nfd] = nc;
			q.push({ nfd, nc });
		}
	}

	if (floor[G-1]==-1) cout << "use the stairs";
	else cout << floor[G-1];
}
