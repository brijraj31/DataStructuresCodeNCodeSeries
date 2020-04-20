#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAX 100001


vector<int> adj[MAX];
bool vis[MAX] = {false};
int parent[MAX] = {0};


int findSet(int s) {
    while (true){
        if(s == parent[s]) return s;
        s = parent[s];
    }
}

void unionSet(int u, int v) {
    int a = findSet(u);
    int b = findSet(v);

    if(a == b) return;
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    parent[b] = a;
}
void dfs(int s, int p = -1) {

    vis[s] = true;
    parent[s] = parent[p];

    for(int x : adj[s]) {
        if(x == p) continue;

        if(vis[x]) {
            parent[s] = min(parent[s], parent[x]);
        }
        else {
            dfs(x, s);
        }
    }
}
void makeDisjointSet(int n) {
    for(int i = 1; i < MAX; ++i) parent[i] = i;

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i, i);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    int u, v;

    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


}