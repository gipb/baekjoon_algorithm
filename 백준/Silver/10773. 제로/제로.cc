#include<iostream>
#include<vector>
using namespace std;

int main(){
    int K;
    vector<int> s;
    cin >> K;
    for(int i=0; i<K; i++){
        int num;
        cin >> num;
        if(num) s.push_back(num);
        else s.pop_back();
    }
    int ans=0;
    for(int i=0; i<s.size(); i++){
        ans+=s[i];
    }
    cout << ans;
    return 0;
}