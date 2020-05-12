
//
// Created by brijr on 30-3-20.
//

#include <iostream>
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
vector<int> adj[MAX];
bool vis[MAX];
int far[MAX];

int main() {

    int t;
    cin >> t;
    while(t--) {

        for(auto & i : adj) {
            i.clear();
        }

        memset(vis, false, MAX * sizeof(bool));
        memset(far, -1, MAX * sizeof(int));


        int n, m;
        cin >> n >> m;
        int u, v;
        for(int i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(1);
        int dis = 0;
        far[1] = 0;
        vis[1] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int x : adj[curr]) {
                if(!vis[x]) {
                    q.push(x);
                    far[x] = far[curr] + 1;
                    vis[x] = true;
                }
            }

        }

        cout << far[n] <<'\n';
    }

    return 0;
}
