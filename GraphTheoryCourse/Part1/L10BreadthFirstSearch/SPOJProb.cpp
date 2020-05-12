
//
// Created by brijr on 31-3-20.
//


/*https://www.spoj.com/problems/PPATH/*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int> adj[MAX];
vector<int> primes;
int dist[MAX];
bool vis[MAX];
bool isPrime(int n) {
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

void buildGraph() {
    for(int i = 1e3; i< 1e4; ++i) {
        if(isPrime(i)) {
            primes.push_back(i);
        }
    }

    for(int i = 0; i < primes.size(); ++i) {
        int elem1 = primes[i];
        int arr1[4];
        arr1[0] = (elem1 / 1000) % 10;
        arr1[1] = (elem1 / 100) % 10;
        arr1[2] = (elem1 / 10) % 10;
        arr1[3] = elem1 % 10;
        for(int j = i + 1; j < primes.size(); ++j) {
            int elem2 = primes[j];
            int arr2[4];
            arr2[0] = (elem2 / 1000) % 10;
            arr2[1] = (elem2 / 100) % 10;
            arr2[2] = (elem2 / 10) % 10;
            arr2[3] = elem2 % 10;
            int count = 0;
            for(int k = 0; k < 4; ++k) {
                if(arr1[k] != arr2[k]) {
                    count ++;
                }
            }
            if(count == 1) {
                adj[primes[i]].push_back(primes[j]);
                adj[primes[j]].push_back(primes[i]);
            }
        }
    }
}



int main() {

    buildGraph();

    int t;
    cin >> t;
    while (t--) {
        memset(dist, -1, MAX * sizeof(int));
        memset(vis, false, MAX * sizeof(bool));
        int a, b;
        cin >> a >> b;

        queue<int> q;
        vis[a] = true;
        dist[a] = 0;
        q.push(a);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == b) {
                break;
            }
            for(int x : adj[curr]) {
                if(!vis[x]) {
                    q.push(x);
                    dist[x] = dist[curr] + 1;
                    vis[x] = true;
                }
            }
        }

        if(dist[b] == -1) {
            cout << "Impossible";
        }
        else {
            cout << dist[b];
        }

        cout << '\n';
    }

}
