#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001
int mod = 1e9 + 7;
int F[MAXN];

int power(int x, int n) {
    int res = 1;
    x = x % mod;

    while(n > 0) {
        if(n & 1) res = (res * 1ll * x) % mod;


        x = (x * 1ll * x) % mod;
        n >>= 1;
    }
    return res;
}
int NCK(int n, int k) {
    if(k > n) return 0;

    int res = F[n];

    res = (res * 1ll * power(F[k], mod - 2)) % mod;

    res = (res * 1ll * power(F[n - k], mod -2)) % mod;

    return res;
}
int main() {
    
    F[0] = F[1] = 1;

    for(int i = 2; i < MAXN; ++i) {
        F[i] = (F[i - 1] * 1ll * i) % mod;
    }

    int q;
    int n , k;

    cin >> q;
    while(q -- ) {
        cin >> n >> k;
        cout << NCK(n, k) <<'\n';
    }

   return 0; 
}