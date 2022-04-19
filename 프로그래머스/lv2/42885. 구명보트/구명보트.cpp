#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<int>());
    
    int fi=0;
    int ei=people.size()-1;
    while(fi<=ei){
        int boat=0;
        boat+=people[fi];
        fi++;
        boat+=people[ei];
        if(boat<=limit){
            ei--;
        }
        answer++;
    }
    
    return answer;
}