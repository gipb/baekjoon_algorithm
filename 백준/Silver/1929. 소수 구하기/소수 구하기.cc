#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	vector<int> prime(N+1,0);
	prime[0] = prime[1] = 1;
	for (int i = 2; i < N + 1; i++) {
		if (prime[i]) continue;
		for (int j = 2; j * i < N + 1; j++) {
			prime[j * i] = 1;
		}
	}

	for (int i = M; i < N + 1; i++) {
		if (prime[i]) continue;
		cout << i << '\n';
	}

	return 0;
}