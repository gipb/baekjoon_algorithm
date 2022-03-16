#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int prime[1001] = {};

void find_prime() {
	prime[0] = prime[1] = 1;
	for (int i = 2; i < 1001; i++) {
		if (prime[i]) continue;
		for (int j = 2; i * j < 1001; j++) prime[i * j] = 1;
	}
}

int main()
{
	int N;
	cin >> N;
	find_prime();
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (!prime[num]) cnt++;
	}

	cout << cnt;
	return 0;
}

