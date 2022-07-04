#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		map <string, int> clothes;

		for (int i = 0; i < n; i++) {
			string c;
			string type;
			cin >> c >> type;
			clothes[type]++;
		}

		int ans = 1;
		for (auto it = clothes.begin(); it != clothes.end(); it++) {
			ans *= (it->second + 1);
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}