#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, M;
	cin >> N >> M;

	vector<string> dd;
	vector<string> bd;
	vector<string> ddbd;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		dd.push_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		bd.push_back(tmp);
	}

	sort(dd.begin(), dd.end(), greater<string>());
	sort(bd.begin(), bd.end(), greater<string>());

	while (dd.size() && bd.size()) {
		if (dd.back() == bd.back()) {
			ddbd.push_back(dd.back());
			dd.pop_back();
			bd.pop_back();
		}
		else if (dd.back() > bd.back()) {
			bd.pop_back();
		}
		else dd.pop_back();
	}

	cout << ddbd.size() << '\n';
	for (int i = 0; i < ddbd.size(); i++) {
		cout << ddbd[i] << '\n';
	}

	return 0;
}