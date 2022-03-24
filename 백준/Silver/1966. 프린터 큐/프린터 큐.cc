#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Q {
	int work;
	int index;
};

int dat[10] = {};

void init() {
	for (int i = 0; i < 10; i++) dat[i] = 0;
}

int find_largest() {
	for (int i = 9; i >= 1; i--) {
		if (dat[i]) return i;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;
		queue<Q> q;
		init();
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			q.push({ num,i });
			dat[num]++;
		}

		int cnt = 0;
		int flag = 1;
		int l = 0;
		while (!q.empty()) {
			if (flag) {
				l = find_largest();
				flag = 0;
			}
			Q now = q.front();
			q.pop();
			if (now.work < l) q.push(now);
			else {
				cnt++;
				dat[l]--;
				flag = 1;
				if (now.index == M) {
					break;
				}
			}
		}

		cout << cnt << '\n';
		
	}
	return 0;
}