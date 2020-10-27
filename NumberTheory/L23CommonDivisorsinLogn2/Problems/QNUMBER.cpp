// Problem Link : https://www.codechef.com/problems/QNUMBER

/* 
Queries About Numbers Problem Code: QNUMBER
*/

/* 
Chef loves number theory very much. Now it is time to solve a new kind of problem.

There is given a natural number N. Chef has to answer Q queries of the form T K.

Here T is the type of query and K is the natural number.
If T=1, Chef must find the number of natural numbers which is divisor of both N and K.
If T=2, Chef must find the number of natural numbers which is divisor of N and is divisible by K.
If T=3, Chef must find the number of natural numbers which is divisor of N and is not divisible by K.

Chef can solve all these queries, but you will be hungry for night if this happens, because Chef will not have free time to cook a meal. Therefore you compromise with him and decided that everyone must do his/her own job. You must program and Chef must cook.

Input
There will be 2 numbers in the first line: N and Q.
Q lines follow with 2 numbers each: T and K

Output
For each of the Q lines you must output the result for corresponding query in separat line.

Example
Input:
12 6
1 6
1 14
2 4
2 3
3 12
3 14

Output:
4
2
2
3
5
6

Explanation
Numbers for each query:
{1,2,3,6}
{1,2}
{4,12}
{3,6,12}
{1,2,3,4,6}
{1,2,3,4,6,12}
Constraints
1<=N<=1012
1<=Q<=5*105
1<=T<=3
1<=K<=1012

*/

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
typedef long long int ll;

unordered_map<ll, ll> fact;
ll n;

ll total;
void init(ll n) {
    total = 1;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count ++;
                n = n / i;
            }
            fact[i] = count;
            total *= (count + 1);
        }
    }
    if (n > 1) {
        fact[n] = 1;
        total *= 2;
    }
}
int main() {

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n;
    init(n);
    int q;
    
    /* for (auto p : fact) {
        cout << p.first << " " << p.second << '\n';
    } */
    cin >> q;
    while (q --){
        ll t , k;
        cin >> t >> k;

        if (t == 1) {
            ll res = 1;

            for (auto p : fact) {
                ll cnt = 0;
                while (k % p.first == 0) {
                    cnt ++;
                    k /= p.first;
                }
                res *= min(cnt, p.second) + 1;
            }
            cout << res << '\n';
        }
        else {
            ll res = 1;
            for (auto p : fact) {
                ll cnt = 0;
                while (k % p.first == 0) {
                    cnt ++;
                    k /= p.first;
                }

                if (cnt > p.second) {
                    res = 0;
                    break;
                }
                res *= (p.second - cnt + 1);
            }

            if (k > 1) res = 0;

            if (t == 2)
                cout << res << '\n';
            else
                cout << total - res << '\n';
        }
    }
    
    return 0;
}