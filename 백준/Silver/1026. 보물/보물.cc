#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N, 0);
	vector<int> B(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), less<int>());

	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans += (A[i] * B[i]);
	}

	cout << ans;

	return 0;
}