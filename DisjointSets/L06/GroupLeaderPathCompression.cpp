#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAX 100001
typedef long long int ll;

vector<int> adj[MAX];
bool vis[MAX] = {false};
int parent[MAX] = {0};


int findSetTer(int a) {
    vector<int> v;

    while(parent[a] > 0) {
        v.push_back(a);
        a = parent[a];
    }

    for(int i = 0; i < v.size(); ++i) 
        parent[v[i]] = a;     // make all entries points to a

    return a;    

}

int findSetRec(int a) {

    if(parent[a] < 0) return a;

    return parent[a] = findSetRec(parent[a]);

}
void unionSet(int u, int v) {
    if(u > v) {
        int temp = u;
        u = v;
        v = temp;
    }
    parent[u] += parent[v];
    parent[v] = u;
}

int main() {
    for(int i = 0; i < MAX; ++i) {
        parent[i] = -1;
    }
    int n, m;
    cin >> n >> m;

    int u, v;

    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        u = findSetRec(u) , v = findSetRec(v);
        if(u != v) unionSet(u, v);
    }

    ll res = 1;

    for(int i = 1; i <= n; ++i) {
        if(parent[i] < 0)
            res = (res * abs(parent[i])) % 1000000007;
    }

    cout << res;
}