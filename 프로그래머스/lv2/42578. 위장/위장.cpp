#include <string>
#include <vector>

using namespace std;

struct Info{
    string category;
    int num;
};

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    vector<Info> category;
    
    int len = clothes.size();
    
    for(int i=0; i<len; i++){
        int flag=0;
        for(int j=0; j<category.size(); j++){
            if(category[j].category == clothes[i][1]){
                category[j].num++;
                flag=1;
                break;
            }
        }
        if(!flag){
            category.push_back({clothes[i][1], 1});
        }
    }
    
    int cnt=1;
    for(int i=0; i<category.size(); i++){
        cnt *= (category[i].num+1);
    }
    answer = cnt-1;
    return answer;
}