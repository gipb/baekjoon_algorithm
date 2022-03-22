#include <string>
#include <vector>

using namespace std;

vector<int> lyan(11, 0);
vector<int> best(11, 0);
int bs = -1;
int p = 0;
vector<int> apeach(11, 0);

void dfs(int level) {
    if (level == 0) {
        int as = 0;
        int ls = 0;
        for (int i = 0; i < 11; i++) {
            if (!(apeach[i] | lyan[i])) continue;
            if (apeach[i] < lyan[i]) ls += (10 - i);
            else as += (10 - i);
        }
        int diff = ls - as;
        if ( diff > 0 && diff >= bs) {
            int flag = 1;
            if (diff == bs) {
                for (int i = 10; i >= 0; i--) {
                    if (best[i] == lyan[i]) continue;
                    if (best[i] > lyan[i]) {
                        flag = 0;
                        break;
                    }
                    break;
                }
            }
            if (flag) copy(lyan.begin(), lyan.end(), best.begin());
            bs = diff;
        }
        return;
    }
    for (int i = p; i < 11; i++) {
        int temp = p;
        lyan[i]++;
        p = i;
        dfs(level - 1);
        p = temp;
        lyan[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, 0);
    copy(info.begin(), info.end(), apeach.begin());
    dfs(n);
    if (bs == -1) {
        answer = vector<int>();
        answer.push_back(-1);
    }
    else copy(best.begin(), best.end(), answer.begin());
    return answer;
}