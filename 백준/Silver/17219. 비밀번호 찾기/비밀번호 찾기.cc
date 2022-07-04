#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map <string, string> secret;
	for (int i = 0; i < n; i++) {
		string site;
		string pw;
		cin >> site >> pw;
		secret[site] = pw;
	}

	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;
		cout << secret[site] << '\n';
	}

	return 0;
}