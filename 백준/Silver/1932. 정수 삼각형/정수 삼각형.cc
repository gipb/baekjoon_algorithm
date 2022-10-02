#include <iostream>
#include <vector>
using namespace std;

void init();
void make_triangle();
int max(int a, int b);
int n; // 삼각형 크기
vector<vector<int>> triangle;

void init() {
	cin >> n;
	triangle = vector<vector<int>>(n, vector<int>(n, 0));
}

void make_triangle() {
	for (int r = 0; r < n; r++) {
		for (int c = 0; c <= r; c++) {
			int num;
			cin >> num;
			if (r == 0)
				triangle[r][c] = num;
			else if (c == 0)
				triangle[r][c] = num + triangle[r - 1][c];
			else
				triangle[r][c] = num + max(triangle[r - 1][c - 1], triangle[r - 1][c]);
		}
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	make_triangle();

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < triangle[n - 1][i])
			ans = triangle[n - 1][i];
	}
	cout << ans;
	return 0;
}