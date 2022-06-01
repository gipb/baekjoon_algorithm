#include<iostream>
using namespace std;

int main() {
	int a, b;

	cin >> a >> b;
	int cnt = 0;
	while (b > a) {
		if (b % 2) {
			if(b%10==1) b /= 10;
			else break;
		}
		else b /= 2;
		cnt++;
	}

	if (a != b) cnt = -2;

	cout << cnt+1;

	return 0;
}