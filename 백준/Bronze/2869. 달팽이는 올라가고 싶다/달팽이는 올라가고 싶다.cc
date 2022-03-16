#include<iostream>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;
    cout << (V - A) / (A - B) + ((V-A)%(A-B)!=0) + 1;
    return 0;
}