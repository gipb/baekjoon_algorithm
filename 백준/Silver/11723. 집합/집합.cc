#include <iostream>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int M;
	cin >> M;
	int dat[21] = {};
	for (int m = 0; m < M; m++) {
		char buf[20];
		
		cin >> buf;

		if (!strncmp(buf, "add", 3)) {
			int num;
			cin >> num;
			dat[num] = 1;
		}
		else if (!strncmp(buf, "remove", 6)) {
			int num;
			cin >> num;
			dat[num] = 0;
		}
		else if (!strncmp(buf, "check", 5)) {
			int num;
			cin >> num;
			cout << dat[num] << '\n';
		}
		else if (!strncmp(buf, "toggle", 6)) {
			int num;
			cin >> num;
			dat[num] ^= 1;
		}
		else if (!strncmp(buf, "all", 3)) {
			for (int i = 1; i < 21; i++) {
				dat[i] = 1;
			}
		}
		else if (!strncmp(buf, "empty", 5)) {
			for (int i = 1; i < 21; i++) {
				dat[i] = 0;
			}
		}
	}
}