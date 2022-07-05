#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> p;

int main() {
	int n, m;
	cin >> n >> m;

	p = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		p[j - 1][k - 1] = 1;
		p[k - 1][j - 1] = 1;
	}

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			int me = p[r][c];
			if (!me) continue;
			for (int i = 0; i < n; i++) {
				if (i == r) continue;
				if (p[c][i]) {
					int tmp = me + p[c][i];
					if (p[r][i]) {
						p[r][i] = p[r][i] > tmp ? tmp : p[r][i];
						p[i][r] = p[r][i];
					}
					else {
						p[r][i] = tmp;
						p[i][r] = tmp;
					}
				}
			}
		}
	}

	int ans = 0;
	vector<int> tmp(n, 0);
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			tmp[r] += p[r][c];
		}
		if (tmp[ans] > tmp[r]) ans = r;
	}

	cout << ans + 1;
	

	return 0;
}