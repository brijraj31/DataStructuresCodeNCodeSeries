
//
// Created by brij on 02/04/20.
//


// Problem Link : https://codeforces.com/problemset/problem/118/E


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int> adj[MAX];
bool vis[MAX] ={false};
int tin[MAX] ={0};
int low[MAX] ={0};

int timer;



bool hasBridge = false;
vector<pair<int, int>> edges;
void dfs(int s, int p = -1) {
    vis[s] = true;

    tin[s] = low[s] = timer++;

    for(int to : adj[s]) {
        if(to == p) {
            continue;
        }
        if(vis[to]) {
            low[s] = min(low[s], tin[to]);
            // back edge

            if(tin[s] > tin[to]) {
                edges.emplace_back(s, to);
            }
        } else {
            // unvisited node

            dfs(to, s);

            low[s] = min(low[s], low[to]);

            if(low[to] > tin[s]) {
                // yes this is bridge node
                hasBridge = true;
                return;
            } else
                edges.emplace_back(s, to);
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

    timer = 0;
    dfs(1);

    if(!hasBridge) {
        for(pair<int, int> x : edges) {
            cout << x.first << " " << x.second << '\n';
        }
    }
    else {
        cout << "0";
    }
    return 0;
}
