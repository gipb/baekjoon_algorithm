#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int N;
	int num;
	cin >> N;
	int arr[8001] = {};
	int sum = 0;
	int cnt = N / 2;
	int mid, range;
	int max_ex[2] = {};
	int max_ex_index[2] = {};
	int min = -1;
	int max = -1;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num + 4000]++;
		sum += num;
	}
	
	for (int i = 0; cnt >= 0; i++) {
		cnt -= arr[i];
		mid = i;
	}

	for (int i = 8000; i >= 0; i--) {
		if (arr[i]) {
			if (max < 0) max = i;
			min = i;
			if (arr[i] >= max_ex[0]) {
				max_ex[1] = max_ex[0];
				max_ex[0] = arr[i];
				max_ex_index[1] = max_ex_index[0];
				max_ex_index[0] = i;
			}
			else if (arr[i] >= max_ex[1]) {
				max_ex[1] = arr[i];
				max_ex_index[1] = i;
			}
		}
	}

	range = max - min;

	double avg = sum / (double)N;
	cout << (int)(round(avg)) << '\n';
	cout << mid - 4000 << '\n';
	if (N == 1) cout << num << '\n';
	else if (max_ex[0] == max_ex[1])
		cout << max_ex_index[1] - 4000 << '\n';
	else cout << max_ex_index[0] - 4000 << '\n';
	cout << range << '\n';


	return 0;
}