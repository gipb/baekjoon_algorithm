#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

int K, N;
vector<int> line;
ll max_len = 0;

void bs_len(int num, ll start, ll end) {
	if (start == end) {
		ll sum = 0;
		for (int i = 0; i < K; i++) {
			sum += (line[i]) / start;
		}
		if (sum < num) return;
		max_len = start;
		return;
	}
	ll mid = (start + end) / 2;
	ll sum = 0;
	int flag = 0;
	for (int i = 0; i < K; i++) {
		sum += (line[i] / mid);
		if (sum >= num) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		if (max_len < mid) max_len = mid;
		return bs_len(num, mid + 1, end);
	}
	else return bs_len(num, start, mid);
}

int main()
{
	cin >> K >> N;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		int len;
		cin >> len;
		line.push_back(len);
		sum += len;
	}
	sort(line.begin(), line.end(), greater<int>());

	long long limit = sum / N;


	bs_len(N, 1, limit);
	cout << max_len;

	return 0;
}