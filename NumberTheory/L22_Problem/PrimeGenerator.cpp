// Problem Link : https://www.spoj.com/problems/PRIME1/


// PRIME1 - Prime Generator

/* Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
Warning: large Input/Output data, be careful with certain languages (though most should be OK if the algorithm is well designed)
Information
After cluster change, please consider PRINT as a more challenging problem. */


#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

bool prime[100001];

bool smallPrime[100001];

vector<int> small;

void init() {
    smallPrime[0] = smallPrime[1] = true;
    for (int i = 2; i * i <= 100001; ++i) {
        if (!smallPrime[i]) {
            for (int j = i * 2; j < 100001; j += i) {
                smallPrime[j] = true;
            }
        }
    }
    for (int i = 2; i < 100001; ++i) {
        if (!smallPrime[i]) {
            small.push_back(i);
        }
    }

    
}

void printPrime(ll m, ll n) {

    if (n <= 10000) {
        for (int i = m; i <= n; ++i) {
            if (!smallPrime[i]) {
                cout << i << '\n';
            }
        }
        cout << '\n';
        return;
    }
    if (m <= 10000) {
        for (int i = m; i <= 100000; ++i) {
            if (!smallPrime[i]) {
                cout << i << '\n';
            }
        }

        m = 100001;
    }

    for (auto x : small) {

        ll start = m + x - (m % x);
        ll end = n - (n % x);
        for (ll i = start; i <= end; i += x) {
            prime[(int)(i - m)] = true;
        }
    }

    for (int i = m; i <= n; ++i) {
        if(!prime[i - m]) {
            cout << i << '\n';
        }
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int t;
    cin >> t;
    while (t --) {
        for (int i = 0; i < 100001; ++i) {
            prime[i] = false;
        }

        ll m, n;

        cin >> m >> n;
        printPrime(m, n);

    }
    return 0;
}
