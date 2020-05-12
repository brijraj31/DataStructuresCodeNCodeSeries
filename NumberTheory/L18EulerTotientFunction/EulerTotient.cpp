#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int phi(int n) {
    int res = n;
    int temp = n;
    for(int i = 2; i * i <= n; ++i) {
        if(temp % i == 0) {
            res /= i;
            res *= (i - 1);
            while(temp % i == 0) {
                temp /= i;
            }
        }
    }

    if(temp > 1){
        res /= n;
        res *= (n - 1);
    }
        

    return res;    
}

int main() {

    int n;
    cin >> n;
    cout << phi(n);
    return 0;
}
