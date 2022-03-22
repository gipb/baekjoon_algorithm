#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    int index=0;
    while(true){
        int p = s.find(' ',index);
        if(p==s.npos) {
            nums.push_back(stoi(s.substr(index)));
            break;
        }
        nums.push_back(stoi(s.substr(index,p)));
        index = p+1;
    }
    sort(nums.begin(), nums.end());
    answer = to_string(nums.front()) + " " + to_string(nums.back());
    return answer;
}