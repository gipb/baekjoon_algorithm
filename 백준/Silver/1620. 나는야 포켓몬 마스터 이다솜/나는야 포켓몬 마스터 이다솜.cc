#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() 
{
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> dict1;
	vector<string> dict2;

	for (int i = 0; i < N; i++) {
		string txt;
		cin >> txt;
		dict2.push_back(txt);
		dict1.insert({ txt,i + 1 });
	}

	for (int i = 0; i < M; i++) {
		string txt;
		cin >> txt;
		if (isalpha(txt[0])) {
			cout << dict1.find(txt)->second << '\n';
		}
		else cout << dict2[stoi(txt) - 1] << '\n';
	}

	return 0;
}