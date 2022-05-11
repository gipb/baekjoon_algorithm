#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    vector<int> change;
    
    int up_down = 0;
    
    for(int i=0; i<len; i++){
        int c1 = name[i]-'A';
        int c2 = 'Z'-name[i]+1;
        int c = c1 > c2 ? c2 : c1;
        change.push_back(c);
        
        up_down += c;
    }
    
    // 연속된 A 위치 찾기
    
    int start = -1;
    int max_start = -1;
    int cnt = 0;
    int max_cnt = 0;
    
    for(int i=0; i<len; i++){
        if(change[i] == 0){
            if(start == -1) start = i;
            cnt++;
        }
        else {
            if(max_cnt < cnt) {
                max_cnt = cnt;
                max_start = start;
            }
            cnt = 0;
            start = -1;
        }
    }
    if(start != -1){
        cnt = len-start;
        if(cnt > max_cnt){
            max_start = start;
            max_cnt = len-start;
        }
    }
    
    int turn;
    if(max_start != -1){
        // 돌아가는 경우
        int end = max_start+max_cnt-1;
    
        int turn_r = (max_start-1)*2 + (len-end-1);
        int turn_l = (len-end-1)*2 + (max_start-1);
    
        turn = turn_r > turn_l ? turn_l : turn_r;
    }
    else turn = 21e8;
    
    
    
    // 질러가는 경우
    
    int st_r = len-1;
    for(int i=len-1; i>0; i--){
        if(change[i]) break;
        st_r--;
    }
    
    int st_l = len-1;
    for(int i=1; i<len; i++){
        if(change[i]) break;
        st_l--;
    }
    
    int st = st_r > st_l ? st_l : st_r;
    
    int left_right = st > turn ? turn : st;
    if (left_right<0) left_right = 0;
    
    answer = up_down + left_right;
    
    
    return answer;
}