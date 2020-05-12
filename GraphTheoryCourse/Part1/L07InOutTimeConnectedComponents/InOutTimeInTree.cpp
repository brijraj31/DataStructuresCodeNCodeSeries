
//
// Created by brijr on 29-3-20.
//

#include <iostream>
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<int> adj[MAX];
bool vis[MAX] = {false};

int inTime[MAX] = {0};
int outTime[MAX] = {0};

int dfs(int s, int t) {
    vis[s] = true;
    inTime[s] = t;
    for(int x : adj[s]) {
        if(!vis[x]) {
            t = max(t, dfs(x, t + 1));
        }
    }

    outTime [s] = t + 1;
    return outTime[s];
}
int main() {
    
/*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    *//*

    int n , e;
    cin >> n >> e;

    for(int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(1, 1);
    for(int i = 1; i <= n; ++i) {
        cout << inTime[i] <<" ";
    }
    cout << '\n';

    for(int i = 1; i <= n; ++i) {
        cout << outTime[i] <<" ";
    }
    cout << '\n';
    return 0;
}*/
