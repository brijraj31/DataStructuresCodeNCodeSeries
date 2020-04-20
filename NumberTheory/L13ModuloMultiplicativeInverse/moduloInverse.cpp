#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int power(int a, int n, int m) {

    int res = 1;
    a = a % m;

    while(n > 0) {
        if(n & 1)
            res = (res * a) % m;

        a = (a * a) % m;
        n >>= 1;    
    }
    return res;
}
int main() {


    int a, m;
    cin >> a >> m;

    // m should be prime and a & m are co primes

    cout << a << "^(-1) (mod "<<m<<") = "<< power(a, m - 2, m);

    return 0;
}