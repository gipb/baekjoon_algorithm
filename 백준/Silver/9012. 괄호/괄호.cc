#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string text;
		cin >> text;
		int flag = 0;
		for (int j = 0; j < text.size(); j++) {
			if (text[j] == '(') flag++;
			else flag--;
			if (flag < 0) break;
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}