#include <string>
#include <vector>
#include <queue>
using namespace std;

int dat[10] = {};

struct Info{
    int work;
    int index;
};

int find_p(){
    int ret = 0;
    for(int i=0; i<10; i++){
        if(dat[i]) ret = i;
    }
    return ret;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<Info> q;
    vector<Info> order;
    for(int i=0; i<priorities.size(); i++){
        q.push({priorities[i], i});
        dat[priorities[i]]++;
    }
    
    while(!q.empty()){
        Info now = q.front();
        q.pop();
        
        int max_p = find_p();
        if(now.work != max_p) q.push(now);
        else {
            order.push_back(now);
            dat[now.work]--;
        }
    }
    
    for(int i=0; i<order.size(); i++){
        if(order[i].index == location) {
            answer = i+1;
            break;
        }
    }
    
    return answer;
}