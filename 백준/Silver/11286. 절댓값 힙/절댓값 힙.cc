#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (int left, int right) {
		return abs(left) == abs(right) ? left > right : abs(left) > abs(right);
	}
};

int N;
priority_queue<int, vector<int>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num) pq.push(num);
		else {
			if (pq.size()) {
				cout << pq.top();
				pq.pop();
			}
			else cout << pq.size();
			cout << '\n';
		}
	}

	return 0;
}