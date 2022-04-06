#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string text;
	while (1) {
		getline(cin, text);
		if (text == ".") break;

		vector<char> check;
		int flag = 0;
		for (int i = 0; text[i]; i++) {
			if (text[i] == '(' || text[i] == '[') check.push_back(text[i]);
			else if (text[i] == ')') {
				if (!check.size() || check.back() != '(') {
					flag = 1;
					break;
				}
				check.pop_back();
			}
			else if (text[i] == ']') {
				if (!check.size() || check.back() != '[') {
					flag = 1;
					break;
				}
				check.pop_back();
			}
		}
		if (check.size()) flag = 1;
		if (flag) cout << "no\n";
		else cout << "yes\n";
	}

	return 0;
}