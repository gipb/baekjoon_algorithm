#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dat[100001] = {};

int main() {
  int N, K;
  cin >> N >> K;

  queue<int> q;
  dat[N] = 1;
  q.push(N);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    if(now == K) break;

    if (now > 0 && !dat[now - 1]) {
      q.push(now - 1);
      dat[now - 1] = dat[now] + 1;
    }
    if(now<100000 && !dat[now+1]){
      q.push(now+1);
      dat[now+1] = dat[now]+1;
    }
    if(now<50001 && !dat[now*2]){
      q.push(now*2);
      dat[now*2] = dat[now]+1;
    }
  }

  cout << dat[K]-1;

  return 0;
}