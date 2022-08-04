#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

void init();
void rev();
void del();

string op; // 수행할 함수
int n; // 배열에 들어갈 수의 개수
string arr; // 배열 입력
deque<int> dq; // 배열 저장

int isError = 0; // 에러 판단
int dir = 0; // 제거 및 출력 방향 0 : 앞에서 1 : 뒤에서

void init() {

	// 입력
	cin >> op;
	cin >> n;
	cin >> arr;

	// initialize
	isError = 0;
	dq = deque<int>();
	dir = 0;

	int start_index = 1;
	int target_index = 0;
	int len = 0;
	while (true) {
		target_index = arr.find(',', start_index);
		if (target_index == arr.npos) break;
		len = target_index - start_index;

		dq.push_back(stoi(arr.substr(start_index, len)));
		start_index = target_index + 1;
	}
	target_index = arr.find(']', start_index);
	len = target_index - start_index;
	if (!len) return;
	dq.push_back(stoi(arr.substr(start_index, len)));
}

void rev() {
	dir = 1 - dir;
}

void del() {
	if (dir) dq.pop_back();
	else dq.pop_front();
}


int main() {
	int T; // 테스트 케이스의 수
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 'R') rev();
			if (op[i] == 'D') {
				if (dq.size() == 0) {
					isError = 1;
					break;
				}
				del();
			}
		}
		if (isError) cout << "error\n";
		else {
			string ans = "";
			ans.push_back('[');
			if (dir) {
				while (dq.size()) {
					string num = to_string(dq.back());
					ans += num;
					ans.push_back(',');
					dq.pop_back();
				}
			}
			else {
				while (dq.size()) {
					string num = to_string(dq.front());
					ans += num;
					ans.push_back(',');
					dq.pop_front();
				}
			}
			if(ans.back()==',')	ans.pop_back();
			ans.push_back(']');
			cout << ans << '\n';
		}
	}
	return 0;
}