

//
// Created by brij on 28/03/20.
//

#include <iostream>
using namespace std;

typedef long long int ll;

ll binExp(ll x, ll n, ll mod) {


    ll res = 1;

    x = x % mod;

    while (n > 0) {
        if(n & 1)
            res = (res * x) % mod;

        x = (x * x) % mod;

        n >>= 1;
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a , p;

    // p should be prime and co prime to a

    cin >> a >> p;
    cout << binExp(a, p - 2, p) << '\n';
    cout << (a * binExp(a, p - 2, p) ) % p;

    return 0;
}




/*
 *
 * 99999999977
 *
 */
