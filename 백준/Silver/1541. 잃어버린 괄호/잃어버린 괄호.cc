#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string txt;
	cin >> txt;

	vector<int> nums;
	vector<char> op;

	int p = 0;

	while (true) {
		int p1 = txt.find('+', p);
		int p2 = txt.find('-', p);
		if (p1 == txt.npos && p2 == txt.npos) break;
		int tp = p1 > p2 ? p2 : p1;
		if (tp < 0) tp = p1 + p2 - tp;
		nums.push_back(stoi(txt.substr(p, tp - p)));
		op.push_back(txt[tp]);
		p = tp+1;
	}
	nums.push_back(stoi(txt.substr(p)));

	int flag = 0;

	// 첫 - 이후로는 부호를 모두 -로 교체
	// 괄호를 활용하여 최대한 수를 줄일 수 있기 때문
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '-') {
			flag = 1;
		}
		if (flag) op[i] = '-';
	}
	
	int ans = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		if (op[i - 1] == '+') ans += nums[i];
		else ans -= nums[i];
	}

	cout << ans;

	return 0;
}