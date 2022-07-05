#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<long long> nums;
	
	long long num;
	cin >> num;
	nums.push_back(num);

	for (int i = 1; i < N; i++) {
		cin >> num;
		nums.push_back(num+nums[i-1]);
	}

	for (int i = 0; i < M; i++) {
		int j, k;
		cin >> j >> k;
		long long ans = nums[k - 1];
		ans -= j < 2 ? 0 : nums[j - 2];
		cout << ans << '\n';
	}

	return 0;
}