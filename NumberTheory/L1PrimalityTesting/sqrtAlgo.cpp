
//
// Created by brij on 26/03/20.
//



# include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = false;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            flag = true;
            break;
        }
    }

    if(n == 1 || flag) {
        cout << "Composite";
    } else cout << "Prime";
}

