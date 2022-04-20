#include <string>
#include <vector>

using namespace std;

long long func(long long i){
    long long ret = i;
    long long a = 1;
    int idx = 0;
    while(true){
        if(i&1) {
            idx++;
            i >>= 1;
        }
        else break;
    }
    if (idx == 0) return ret+1;
    ret ^= (a<<idx);
    ret ^= (a<<(idx-1));
    
    return ret;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0; i<numbers.size(); i++){
        answer.push_back(func(numbers[i]));
    }
    
    return answer;
}