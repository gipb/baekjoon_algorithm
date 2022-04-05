#include<iostream>
#include<vector>
using namespace std;

struct Bigguy {
	int w, h;
};

int main()
{
	int N;
	cin >> N;
	vector<Bigguy> b;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		b.push_back({ x,y });
	}

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (j == i) continue;
			if (b[i].w < b[j].w && b[i].h < b[j].h) cnt++;
		}
		cout << cnt << ' ';
	}

	return 0;
}