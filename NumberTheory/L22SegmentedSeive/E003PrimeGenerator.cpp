// Problem Link : https://www.spoj.com/problems/PRIME1/

/* 
PRIME1 - Prime Generator
#number-theory

Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!
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

 */

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
vector<int> primes;
int prime[100001];

void sieve(int maxN) {
    vector<int> arr(maxN + 1, 0);

    arr[1] = 1;
    for (int i = 2; i <= maxN; ++i) {
        if (arr[i] == 0) {
            for (int j = 2 * i; j <= maxN; j+=i) {
                arr[j] = 1;
            }
        }
    }

    for (int i = 2; i <= maxN; ++i) {
        if (arr[i] == 0) 
            primes.push_back(i);
    }
}

void init(int L, int R) {
    if (L == 1) L ++;

    int maxN = R - L + 1;
    vector<int> arr(maxN, 0);

    for (long long int p : primes) {
        if (p * p <= R) {
            int i = (L / p) * p;

            if (i < L) i+= p;

            for (; i <= R; i+= p) {
                if (i != p)
                    arr[i -  L] = 1;
            }
        }
    }

    for (int i = 0; i < maxN; ++i) {
        if (arr[i] == 0) {
            cout << L + i << '\n';
        }
    }
}
int main() {
    sieve(100000);
    int t, L, R;

    cin >> t;
    while (t --) {
        cin >> L >> R;
        init(L, R);
        cout << '\n';
    }
}