#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> nums;

int dp(int n, int k) {
	if (nums[n]) return nums[n];

	int i = 1;
	int ret;
	while (true) {
		if (pow(i, 2) > n) break;
		ret = nums[n - pow(i, 2)] + nums[pow(i, 2)];
		if (ret == k) return nums[n] = ret;
		i++;
	}
	return nums[n] = 0;

}

int main() {

	int n;
	cin >> n;

	nums = vector<int>(n + 1, 0);

	int i = 1;
	while (true) {
		if (pow(i, 2) > n) break;
		nums[pow(i, 2)] = 1;
		i++;
	}

	for (int k = 2; k < 5; k++) {
		for (int j = 2; j < n+1; j++) {
			int ret = dp(j, k);
		}
	}

	cout << nums[n];

	return 0;
}