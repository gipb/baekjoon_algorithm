#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> stack;
	vector<char> ans;
	int t = 1;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		while (true) {
			if (!stack.size()) {
				stack.push_back(t++);
				ans.push_back('+');
				continue;
			}
			if (num > stack.back()) {
				stack.push_back(t++);
				ans.push_back('+');
				continue;
			}
			else if (num == stack.back()) {
				stack.pop_back();
				ans.push_back('-');
				break;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}