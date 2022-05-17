#include <string>
#include <vector>
#include <set>
using namespace std;

void dfs(int level);
int check_prime(int n);

int len;
int tmp=0;
vector<int> num;
vector<int> used;
set<int> numset;

void dfs(int level){
    if(check_prime(tmp)) numset.insert(tmp);
    if(level==len){
        return;
    }
    
    for(int i=0; i<len; i++){
        if(used[i]) continue;
        tmp*=10;
        tmp+=num[i];
        used[i]=1;
        dfs(level+1);
        used[i]=0;
        tmp-=num[i];
        tmp/=10;
    }
}

int check_prime(int n){
    if(n<2) return 0;
    if(n==2) return 1;
    for(int i=2; i<n; i++){
        if(!(n%i)) return 0;
    }
    return 1;
}

int solution(string numbers) {
    int answer = 0;
    len = numbers.size();
    used = vector<int>(len, 0);
    for(int i=0; i<len; i++){
        num.push_back(numbers[i]-'0');
    }
    
    dfs(0);
    
    answer = numset.size();
    
    return answer;
}