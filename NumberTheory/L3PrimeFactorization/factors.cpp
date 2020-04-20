/*
//
// Created by brij on 27/03/20.
//

#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;


    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            cout << i << " ";
            if(n / i != i) {
                cout << n / i <<" ";
            }
        }
    }
}
*/
