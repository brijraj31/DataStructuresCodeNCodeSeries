
//
// Created by brij on 28/03/20.
//

#include <iostream>
typedef long long int ll;
using namespace std;

ll binMul(ll a, ll b, ll mod) {

    ll res = 0;

    a = a % mod;

    while (b > 0) {
        if(b & 1)
            res = (res + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }

    return res;

}

ll binExp(ll x, ll n, ll mod) {

    ll res = 1;

    x = x % mod;

    while (n > 0) {
        if(n & 1)
            //res = binMul(res ,x ,mod);
            res = (res * x) % mod;

        //x = binMul(x , x,  mod);
        x = (x * x) % mod;
        n >>= 1;
    }

    return res;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;

    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;

        ll max = 1;
        ll sec = a - b;
        if(sec == 0) {
            ll mod = 1e9 + 7;
            ll temp = binExp(a, n , mod);
            temp = (temp + binExp(b, n, mod)) % mod;

            cout << temp << '\n';
            continue;
        }

        for(ll i = 1; i * i <= sec; ++i) {
            if(sec % i == 0) { // i is a factor of a - b

                // calculate whether i and sec / i divides a ^ n + b ^ n;
               ll temp = binExp(a, n, i);
               temp = (temp + binExp(b, n, i)) % i;

               if(temp == 0) { // this factor divides a ^ n + b ^ n;
                   if(i > max) {
                       max = i;
                   }
               }

               if(sec / i != i) {
                   ll nn = sec / i;

                   temp = binExp(a, n, nn);
                   temp = (temp + binExp(b, n, nn)) % nn;

                   if(temp == 0) {
                       if(nn > max) {
                           max = nn;
                       }
                   }
               }
            }
        }


        cout << max << '\n';

    }

    return 0;
}



/*
 * 99999999977
 */