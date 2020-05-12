// Problem Link : https://www.spoj.com/problems/DCEPCA03/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001
typedef long long int ll;
ll phi[MAXN];

void initalize () {

    for(int i = 0; i < MAXN; ++i) {
        phi[i] = i;
    }

    for (int i = 2; i < MAXN; ++i) {
        if(phi[i] == i) {
            for (int j = i ; j < MAXN; j += i) {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }

    
    for(int i = 2; i < MAXN; ++i) {
        phi[i] = phi[i - 1] + phi[i];
    }

    
}

int main() {

    initalize();

    int t, q;
    cin >> t;
    while (t --) {
        cin >> q;
        cout << phi[q] * phi[q] << '\n';
    }

    return 0;
}