#include<iostream>
#include<string>
#include<vector>
using namespace std;

int board[8][8] = {};

// R, L, B, T, RT, LT, RB, LB
int dr[] = { 0,0,1,-1,-1,-1,1,1 };
int dc[] = { 1,-1,0,0,1,-1,1,-1 };
vector<string> d = { "R","L","B","T","RT","LT","RB","LB" };

int find_index(string cmd) {
	for (int i = 0; i < d.size(); i++) {
		if (d[i] == cmd) return i;
	}
}

int main()
{	
	string king, stone;
	int N;

	cin >> king >> stone >> N;

	int kc = king[0] - 'A';
	int kr = 8 - atoi(&king[1]);
	int sc = stone[0] - 'A';
	int sr = 8 - atoi(&stone[1]);

	board[kr][kc] = 1;
	board[sr][sc] = 2;

	for (int i = 0; i < N; i++) {
		string cmd;

		cin >> cmd;
		int di = find_index(cmd);

		int nkr = kr + dr[di];
		int nkc = kc + dc[di];
		if (nkr < 0 || nkr >= 8 || nkc < 0 || nkc >= 8) continue;
		if (board[nkr][nkc] == 2) {
			int nsr = sr + dr[di];
			int nsc = sc + dc[di];
			if (nsr < 0 || nsr >= 8 || nsc < 0 || nsc >= 8) continue;
			board[nsr][nsc] = 2;
			sr = nsr; sc = nsc;
		}
		board[nkr][nkc] = 1;
		board[kr][kc] = 0;
		kr = nkr; kc = nkc;
	}

	king[0] = kc + 'A';
	king[1] = 8 - kr + '0';
	stone[0] = sc + 'A';
	stone[1] = 8 - sr + '0';

	cout << king << '\n' << stone;

	return 0;
}