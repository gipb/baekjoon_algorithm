#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int ans;
	int cnt = 0;
	while (true) {
		if (q.size() == 1) {
			ans = q.front();
			break;
		}
		if (cnt % 2) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		else { 
			q.pop(); 
		}
		cnt++;
	}

	cout << ans;

	return 0;
}