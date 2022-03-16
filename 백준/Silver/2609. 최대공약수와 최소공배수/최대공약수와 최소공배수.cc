#include<iostream>
using namespace std;

int prime[10001] = {};
int DATa[10001] = {};
int DATb[10001] = {};

int find_divisor(int num, int dat[10001]) {
	int j = 1;
	dat[j]++;
	j++;
	while (num > 1) {
		if (prime[j]) {
			j++;
			continue;
		}
		if (num % j == 0) {
			dat[j]++;
			num /= j;
			continue;
		}
		j++;
	}
	return j;
}

int main() {
	int a, b;
	cin >> a >> b;

	// 100이하의 소수 찾기
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 0; i < 10001; i++) {
		if (prime[i] == 1) continue;
		for (int j = i + 1; j < 10001; j++) {
			if (j % i == 0) prime[j] = 1;
		}
	}

	// 약수 구하기 및 최대 소인수 구하기
	int a_i = find_divisor(a, DATa);
	int b_i = find_divisor(b, DATb);
	int max_i = 0;
	if (a_i > b_i) max_i = a_i;
	else max_i = b_i;

	// 최대 공약수, 최소 공배수 출력
	int GCD = 1;
	int LCM = 1;
	for (int i = 0; i <= max_i; i++) {
		if (DATa[i] > DATb[i]) {
			for (int j = 0; j < DATb[i]; j++) GCD *= i;
		}
		else {
			for (int j = 0; j < DATa[i]; j++) GCD *= i;
		}
	}

	LCM = a * b / GCD;

	cout << GCD << endl << LCM;

	return 0;
}