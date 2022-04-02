#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Pos{
    int x,y;
};

bool cmp(Pos left, Pos right){
    return left.y==right.y? left.x < right.x : left.y < right.y;
}

int main(){
    int N;
    vector<Pos> l;
    cin >> N;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        l.push_back({x,y});
    }
    sort(l.begin(), l.end(), cmp);
    for(int i=0; i<l.size(); i++){
        cout<< l[i].x <<' '<<l[i].y<<'\n';
    }
    return 0;
}