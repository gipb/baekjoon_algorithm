#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File {
    string head;
    string num;
};

File makefile(string str){
    int index=0;
    string head = "";
    string num = "";
    for(int i = index; i<str.size(); i++){
        if(!isdigit(str[i])) head += tolower(str[i]);
        else {
            index = i;
            break;
        }
    }
    for(int i = index; i<str.size(); i++){
        if(isdigit(str[i])) num += str[i];
        else break;
    }
    
    File ret = {head, num};
    
    return ret;
}

bool cmp (string left, string right){
    File left_f = makefile(left);
    File right_f = makefile(right);
    return left_f.head == right_f.head ? 
        stoi(left_f.num) < stoi(right_f.num) : 
        left_f.head < right_f.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(), files.end(), cmp);
    answer = files;
    return answer;
}