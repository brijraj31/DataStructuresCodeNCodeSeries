#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    cout << "Enter Number of primes";
    int n;
    cin >> n;

    int mod = 1e9 + 7;
    int total = 1;
    for(int i = 0; i < n; ++i) {
        int num , power;

        cout << "Enter the number and power ";
        cin >> num >> power;

        total = ((total * 1ll) * (power + 1ll)) % mod; 
    }

    cout << total;
    return 0;
}