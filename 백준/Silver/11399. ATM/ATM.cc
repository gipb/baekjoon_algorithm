#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	vector<int> p;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		p.push_back(t);
	}

	sort(p.begin(), p.end(), greater<int>());

	int cnt = 0;
	for (int i = 0; i < p.size(); i++) {
		cnt += p[i] * (i + 1);
	}

	cout << cnt;

	return 0;
}