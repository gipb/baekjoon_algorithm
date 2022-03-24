#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

vector<int> trees;

ll check(int need, int mid) {
	ll len = 0;
	for (int i = 0; i < trees.size(); i++) {
		len += trees[i] > mid ? trees[i] - mid : 0;
		if (len > need) return len;
	}
	return len;
}

int bs(int need, int start, int end) {
	if (start == end) {
		ll len = check(need, end);
		if (len < need) return start - 1;
		return start;
	}
	int mid = (start + end) / 2;
	ll len = check(need, mid);
	if (len < need) return bs(need, start, mid);
	else return bs(need, mid + 1, end);
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tree;
		cin >> tree;
		trees.push_back(tree);
	}
	sort(trees.begin(), trees.end());

	int H = bs(M, 0, trees.back());

	cout << H;

	return 0;
}