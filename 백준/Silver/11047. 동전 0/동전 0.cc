#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> coin;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		coin.push_back(num);
	}

	int cnt = 0;
	while (K) {
		if (coin.back() > K) {
			coin.pop_back();
			continue;
		}
		K -= coin.back();
		cnt++;
	}

	cout << cnt;

	return 0;
}