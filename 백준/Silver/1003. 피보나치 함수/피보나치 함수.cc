#include<iostream>
#include<vector>
using namespace std;

struct fib {
	int zero, one;
};

fib arr[41] = {};

fib fibonacci(int n) {
	if (arr[n].zero != 0 || arr[n].one != 0) return arr[n];
	if (n == 0) return arr[n] = {1,0};
	if (n == 1) return arr[n] = { 0,1 };
	return arr[n] = { (fibonacci(n - 1).zero + fibonacci(n - 2).zero),
		(fibonacci(n - 1).one + fibonacci(n - 2).one) };
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		fib t = fibonacci(n);
		cout << t.zero << ' ' << t.one << '\n';
	}
	return 0;
}