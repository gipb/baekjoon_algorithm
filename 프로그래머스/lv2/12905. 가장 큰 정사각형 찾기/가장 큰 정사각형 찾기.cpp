#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> Board;
int R, C;
int max_len;

int check(int r, int c) {
    for (int dr = 0; dr < max_len; dr++) {
        for (int dc = 0; dc < max_len; dc++) {
            if (!Board[r + dr][c + dc]) return 0;
        }
    }
    return 1;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    Board = board;
    R = board.size();
    C = board[0].size();

    max_len = R > C ? C : R;
    int flag = 1;
    while (flag) {
        for (int r = 0; r < R - max_len + 1; r++) {
            for (int c = 0; c < C - max_len + 1; c++) {
                flag = check(r, c);
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) {
            answer = max_len * max_len;
            break;
        }
        else {
            flag = 1;
            max_len--;
        }
    }


    return answer;
}