#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	string txt;
	cin >> txt;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int len = 0;
		if (txt[i] == 'O')
			continue;
		else {
			while (txt[i + 1] == 'O' && txt[i + 2] == 'I') {
				len++;
				if (len == n) {
					len--;
					ans++;
				}
				i += 2;
			}
			len = 0;
		}
	}

	cout << ans;

	return 0;
}