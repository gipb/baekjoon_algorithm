#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<int> numbers;

int check(int num, int start, int end) {
	if (start == end) return 0;
	int mid = (start + end) / 2;
	if (num == numbers[mid]) return 1;
	if (num > numbers[mid]) return check(num, mid + 1, end);
	if (num < numbers[mid]) return check(num, start, mid);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	numbers = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());
	
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int flag = check(num, 0, N);
		if (flag) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}

