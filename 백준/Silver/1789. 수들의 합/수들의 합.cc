#include<iostream>
using namespace std;

int main() {
	long long S;
	cin >> S;
	long long N = 1;
	while (true) {
		long long sum = N * (N + 1) / 2;
		if (sum > S) break;
		N++;
	}

	cout << N-1;
	return 0;
}