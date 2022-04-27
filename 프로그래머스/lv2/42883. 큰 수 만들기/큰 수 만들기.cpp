#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    answer = number;
    int index=0;
    while(k>0){
        // 체크하는 k+1개 중 최댓값 (같은 값이라면 먼저 나온 것)
        int max_num = -1;
        int max_i = 0;
        
        // 지워야 할 갯수 + 1 개를 확인
        for(int i=index; i<=index+k; i++){
            if(index+k==answer.size()) {
                answer = answer.substr(0,index);
                k=0;
                break;
            }
            int now = answer[i]-'0';
            if(max_num < now) {
                max_num = now;
                max_i = i;
            }
        }
        
        if(!k) break;
        
        answer = answer.substr(0,index) + answer.substr(max_i);
        k -= (max_i-index);
        index++;
    }    
    
    return answer;
}