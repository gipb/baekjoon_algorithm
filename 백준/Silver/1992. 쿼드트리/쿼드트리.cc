#include <iostream>
#include <vector>
#include <string>
using namespace std;

void split_dfs(int r, int c, int s);
void dfs(int r, int c, int s);

vector<string> v;

string ans = "";

void split_dfs(int r, int c, int s) {
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			dfs(r + y * s / 2, c + x * s / 2, s / 2);
		}
	}
}

void dfs(int r, int c, int s) {
	char now = v[r][c];
	int flag = 0;
	for (int y = 0; y < s; y++) {
		for (int x = 0; x < s; x++) {
			if (now != v[r + y][c + x]) {
				ans.push_back('(');
				flag = 1;
				split_dfs(r, c, s);
				ans.push_back(')');
				return;
			}
		}
	}
	ans.push_back(now);
}

int main(){

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string txt;
		cin >> txt;
		v.push_back(txt);
	}

	dfs(0, 0, n);

	cout << ans;

	return 0;
}