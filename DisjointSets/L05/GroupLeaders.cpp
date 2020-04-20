#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAX 100001


vector<int> adj[MAX];
bool vis[MAX] = {false};
int parent[MAX] = {0};


int findSet(int a) {
    while(parent[a] > 0)
        parent[a];
    return a;   
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

        u = findSet(u) , v = findSet(v);
        if(u != v) unionSet(u, v);
    }


}