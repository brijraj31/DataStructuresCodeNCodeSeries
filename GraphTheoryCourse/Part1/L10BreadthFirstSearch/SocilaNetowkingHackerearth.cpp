
//
// Created by brijr on 31-3-20.
//

#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

vector<int> adj[MAX];
bool vis[MAX];

int dis[MAX];

int main() {
    int n , m;
    cin >> n >> m;
    int u, v;

    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int query;
    cin >> query;

    while (query --) {
        int d;
        cin >> u >> d;
        memset(vis, false, MAX * sizeof(bool));
        memset(dis, -1, MAX * sizeof(int));
        queue<int> q;
        q.push(u);
        dis[u] = 0;
        vis[u] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int x : adj[curr]) {
                if(!vis[x]) {
                    q.push(x);
                    dis[x] = dis[curr] + 1;
                    vis[x] = true;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(dis[i] == d) count ++;
        }

        cout << count << '\n';
    }
}
