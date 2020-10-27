/* 
Given N, you have to answer Q queries, in each query you will be given a number K, you have to find count of common divisors of N and K

N <= 10^12
K <= 10^12
Q <= 5 * 10^5

N   K
12  3
5
8
6

Q1 : 1 {1}
Q2 : 3 {1, 2, 4}
Q3 : 4 {1, 2, 3, 6}

*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

unordered_map<int, int> fact;
int n;
void init() {
    int temp = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count ++;
                n = n / i;
            }
            fact[i] = count;
        }
    }
    if (n > 1) {
        fact[n] = 1;
    }
}
int main() {


    
    cin >> n;
    init();
    int q;
    
    for (auto p : fact) {
        cout << p.first << " " << p.second << '\n';
    }
    cin >> q;
    while (q --){
        int k;
        cin >> k;
        int total = 1;
        for (auto p : fact) {
            int count = 0;
            while (k % p.first == 0) {
                count ++;
                k = k / p.first;
            }
            total = total * (min(count, p.second) + 1);
        }

        cout << total << '\n';
    }
    
    return 0;
}