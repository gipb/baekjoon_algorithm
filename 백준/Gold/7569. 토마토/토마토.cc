#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void init();
int bfs();
bool isValid(int r, int c, int h);
bool isCorrect();

struct Info {
  int r;
  int c;
  int h;
  int cnt;
};

int N;
int M;
int H;
vector<vector<vector<int>>> box;
vector<vector<vector<int>>> used;

// 방향 배열
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {0, 0, 0, 0, 1, -1};
int dh[] = {1, -1, 0, 0, 0, 0};

void init() {
  cin >> M >> N >> H;

  box =
      vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(H, 0)));
  used =
      vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(H, 0)));

  for (int h = 0; h < H; h++) {
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < M; c++) {
        cin >> box[r][c][h];
      }
    }
  }
}

int bfs() {
  int ret = 0;
  queue<Info> q;
  for (int h = 0; h < H; h++) {
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < M; c++) {
        if (box[r][c][h] == 1) {
          q.push({r, c, h, 0});
          used[r][c][h] = 1;
        }
      }
    }
  }
  while (!q.empty()) {
    Info now = q.front();
    q.pop();

    ret = now.cnt;

    for (int i = 0; i < 6; i++) {
      int nr = now.r + dr[i];
      int nc = now.c + dc[i];
      int nh = now.h + dh[i];
      if (!isValid(nr, nc, nh)) continue;
      box[nr][nc][nh] = 1;
      q.push({nr, nc, nh, now.cnt + 1});
      used[nr][nc][nh] = 1;
    }
  }

  return ret;
}

bool isValid(int r, int c, int h) {
  if (r < 0 || r >= N) return false;
  if (c < 0 || c >= M) return false;
  if (h < 0 || h >= H) return false;
  if (used[r][c][h]) return false;
  if (box[r][c][h]) return false;
  return true;
}

bool isCorrect() {
  for(int h=0; h<H; h++){
    for(int r=0; r<N; r++){
      for(int c=0; c<M; c++){
        if(used[r][c][h]) continue;
        if(box[r][c][h]) continue;
        return false;
      }
    }
  }
  return true;
}

int main() {
  init();
  int ans = bfs();
  if (isCorrect()) cout << ans;
  else cout << -1;

    return 0;
}