#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> group;
	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		group.push_back(i);
	}

	int i = -1;
	while (group.size()) {
		i += K;
		i %= group.size();
		answer.push_back(group[i]);
		group.erase(group.begin()+i);
		i--;
	}
	cout << '<';
	for (int i = 0; i < answer.size() - 1; i++) {
		cout << answer[i] << ", ";
	}
	cout << answer.back() << '>';

	return 0;
}