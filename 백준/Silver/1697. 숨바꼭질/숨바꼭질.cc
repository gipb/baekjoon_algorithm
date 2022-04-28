#include <iostream>
#include <queue>
using namespace std;

int dat[100001] = {};

int main() {

	int N, K;
	cin >> N >> K;

	string str_N, str_K;
	int ans = 0;

	// 찾으러 갈 위치가 더 작은 경우 - 만 가능
	if (N > K) ans = N - K;

	else {
		queue<int> q;

		q.push(N);
		dat[N] = 1;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (now == K) break;

			int n[3] = { now * 2, now + 1, now - 1 };
			for (int i = 0; i < 3; i++) {
				if (n[i] > 100000 || n[i] < 0) continue;
				if (dat[n[i]]) continue;
				q.push(n[i]);
				dat[n[i]] = dat[now] + 1;
			}
		}

		ans = dat[K] - 1;
	}

	cout << ans;

	return 0;
}