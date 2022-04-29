#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num) pq.push(num);
		else if (pq.empty()) cout << 0 << '\n';
		else {
			cout << pq.top() << '\n';
			pq.pop();
		}
	}

	return 0;
}