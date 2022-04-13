#include<iostream>
#include<vector>
using namespace std;

int main()
{	
	int N, r, c;
	cin >> N >> r >> c;

	vector<int> num(N, 0);
	int i = 0;
	while (i<N) {
		int check = 1 << (N - 1 - i);
		if (r >= check) {
			if (c >= check) {
				num[i] = 3;
				c -= check;
			}
			else num[i] = 2;
			r -= check;
		}
		else {
			if (c >= check) {
				num[i] = 1;
				c -= check;
			}
			else num[i] = 0;
		}
		i++;
	}

	int ans = 0;

	for (int j = 0; j < N; j++) {
		ans *= 4;
		ans += num[j];
	}

	cout << ans;

	return 0;
}