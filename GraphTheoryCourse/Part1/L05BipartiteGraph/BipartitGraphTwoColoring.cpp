
//
// Created by brijr on 29-3-20.
//

#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define MAX 100001
vector<int> adj[MAX];

bool vis[MAX];

int color[MAX];

bool dfs(int s, int col) {
    vis[s] = true;
    color[s] = col;
    for(int i = 0; i < adj[s].size(); ++i) {
        if(!vis[adj[s][i]]) {
            if(!dfs(adj[s][i], col ^ 1)) {
                return false;
            }
        } else if(color[s] == color[adj[s][i]]) return false;
    }
    return true;
}
int main() {

ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < MAX; ++i) {
        vis[i] = false;
        color[i] = 0;
    }
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    color[1] = 0;
    cout << dfs(1, 0) ? "Yes" : "No";

    return 0;
}

