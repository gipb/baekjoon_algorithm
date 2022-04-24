#include <string>
#include <vector>
using namespace std;

// 전역변수 선언
vector<string> Board;       // 블록판
vector<vector<int>> check;  // 2X2 블록 체크용

// 2X2
int dr[]={0,0,1,1};
int dc[]={0,1,0,1};

// 블럭 제거 후 떨어질 때
void block_fall(int c, int m){
    for(int r=m-1; r>=1; r--){
        if(Board[r][c] != '_') continue;
        for(int tr = r-1; tr>=0; tr--){
            if(Board[tr][c] == '_') continue;
            char temp = Board[tr][c];
            Board[tr][c] = Board[r][c];
            Board[r][c] = temp;
            break;
        }
    }
}

// 2X2 체크
void check_square(int r, int c){
    char block = Board[r][c];
    for(int i=1; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(Board[nr][nc] != block) return;
    }
    // 체크 후 체크보드에 기록
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        check[nr][nc] = 1;
    }
    return;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    Board = board;
    
    while(true){
        // while loop 탈출조건, answer가 늘어나지 않으면 탈출
        int temp = answer;
        // 체크판 초기화
        check = vector<vector<int>>(m, vector<int>(n,0));
        
        // 블록 체크 
        for(int r=0; r<m-1; r++){
            for(int c=0; c<n-1; c++){
                if(Board[r][c]=='_') continue;
                check_square(r,c);
            }
        }
        
        // 체크된 블록 없애기
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(check[r][c]) {
                    Board[r][c] = '_';
                    answer++;
                }
            }
        }
        
        // 탈출조건
        if (answer==temp) break;
        
        // 블록 제거 후 블록판 정리
        for(int c=0; c<n; c++){
            block_fall(c,m);
        }
    }
    
    
    return answer;
}