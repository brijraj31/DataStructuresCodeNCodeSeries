
//
// Created by brijr on 29-3-20.
//

#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define MAX 100001
vector<int> adj[MAX];

bool vis[MAX];
int dis[MAX];

void dfs(int s) {
    vis[s] = true;

    for(int i = 0; i < adj[s].size(); ++i) {
        if(!vis[adj[s][i]]) {
            dis[adj[s][i]] = dis[s] + 1;
            dfs(adj[s][i]);
        }
    }
}
int main() {

    
ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < MAX; ++i) {
        vis[i] = false;
        dis[i] = INT_MAX;
    }
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s;
    cin >> s;
    dis[s] = 0;
    dfs(s);

    for(int i = 1; i <= n; ++i) {
        cout << s << " " << i <<" "<< dis[i] <<'\n';
    }
    return 0;
}
