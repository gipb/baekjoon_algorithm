#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
 
    string txt;
    string tmp;
    
    int txt_l;
        
    for(int i=0 ; i<n; i++){
        if(i==0) {
            cin >> txt;
            txt_l = txt.size();
            continue;
        }
        else cin >> tmp;
        
        for(int j=0; j<txt_l; j++){
            if(txt[j] == '?') continue;
            if(txt[j] != tmp[j]) {
                txt[j] = '?';
            }
        }
    }
    
    cout << txt;
    return 0;
}