
//
// Created by brijr on 30-3-20.
//

#include <iostream>
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

vector<int> adj[MAX];
bool vis[MAX] = {false};
int subSize[MAX] = {0};

void dfs(int s) {
    vis[s] = true;
    int count = 1;
    for(int x : adj[s]) {
        if(!vis[x]) {
            dfs(x);
            count += subSize[x];
        }
    }
    subSize[s] = count;
}
int main() {

    int n;
    cin >> n;
    int u, v;
    for(int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    for(int i = 1; i <= n; ++i)
        cout << subSize[i] << " ";


    return 0;
}
