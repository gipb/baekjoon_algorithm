#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
    int r, c;
    int dir;
};

int change_dir(int r, int c, int dir);
void make_route(int R, int C);

// 상우하좌
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

vector<vector<Info>> routes; // 경로 저장 배열

int n, m; // 행, 열
vector<string> Grid; // 전역 변수 grid
vector<vector<int>> used;

int change_dir(int r, int c, int dir) {
    char target = Grid[r][c];
    if (target == 'S') return dir;
    if (target == 'R') return (dir + 1) % 4;
    if (target == 'L') return (dir + 3) % 4;
}

void make_route(int R, int C) {
    for (int i = 0; i < 4; i++) {
        // 각 격자에서 사방으로 빛이 시작하는 경우를 체크
        vector<Info> route;
        int r = R;
        int c = C;
        int dir = i;
        
        int flag=0;
        while (true) {
            used[r][c] |= (1<<dir);
            route.push_back({ r,c,dir });
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            nr = nr > 0 ? nr % n : (nr + n) % n;
            nc = nc > 0 ? nc % m : (nc + m) % m;
            dir = change_dir(nr, nc, dir);
            // 첫 번째 격자에서 첫 번째 빛의 경로 방향이 같으면 싸이클 완성
            if (used[nr][nc] & (1<<dir)) {
                if(nr==R && nc==C && dir == i){
                    flag=1;
                }
                break;
            }
            r = nr;
            c = nc;
        }
        if(flag) routes.push_back(route);
    }
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    n = grid.size();
    m = grid[0].size();
    Grid = grid;
    used = vector<vector<int>>(n, vector<int>(m,0));
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            // 모든 경로 저장
            make_route(r, c);
        }
    }

    for (int r = 0; r < routes.size(); r++) {
        answer.push_back(routes[r].size());
    }

    sort(answer.begin(), answer.end());

    return answer;
}