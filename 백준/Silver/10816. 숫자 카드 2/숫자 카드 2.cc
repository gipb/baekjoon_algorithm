#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Info {
	int card;
	int cnt;
};

int N;
vector<Info> have;
vector<Info> organized;

int bs(int num, int start, int end) {
	if (start == end) return -1;
	int mid = (start + end) / 2;
	if (num > organized[mid].card) {
		return bs(num, mid + 1, end);
	}
	else if (num < organized[mid].card) {
		return bs(num, start, mid);
	}
	else return mid;
}

bool cmp(Info left, Info right) {
	return left.card < right.card;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	have = vector<Info>(N,{0,0});
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		have[i] = { num,1 };
	}

	sort(have.begin(), have.end(), cmp);

	int num = 21e8;
	int min_i = 0;
	int max_i = 0;

	for (int i = 0; i < N; i++) {
		if (num == 21e8) {
			num = have[i].card;
			continue;
		}
		if (num == have[i].card) {
			max_i = i;
		}
		else {
			num = have[i].card;
			organized.push_back({ have[min_i].card, max_i - min_i + 1 });
			min_i = i;
			max_i = i;
		}
	}
	organized.push_back({ have[min_i].card, max_i - min_i + 1 });

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int index = bs(num,0,organized.size());
		if (index == -1) cout << 0 << ' ';
		else {
			cout << organized[index].cnt<<' ';
		}
	}


	return 0;
}