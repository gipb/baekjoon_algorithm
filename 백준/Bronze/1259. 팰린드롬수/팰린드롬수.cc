#include<iostream>
using namespace std;

int main() {
    int num;
    while (true) {
        cin >> num;
        if (num == 0)
            break;
        int temp = num;
        int len;
        int arr[5] = {};
        for (int i = 0; i<5; i++) {
            arr[i] = temp % 10;
            temp /= 10;
            len = i+1;
            if (temp == 0)
                break;
        }
        if (len == 1)
            cout << "yes" << endl;
        else if (len == 2 && arr[0] == arr[1])
            cout << "yes" << endl;
        else if (len == 3 && arr[0] == arr[2])
            cout << "yes" << endl;
        else if (len == 4 && arr[0] == arr[3] && arr[1] == arr[2])
            cout << "yes" << endl;
        else if (len == 5 && arr[0] == arr[4] && arr[1] == arr[3])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}