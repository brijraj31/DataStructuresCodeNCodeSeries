
//
// Created by brijr on 1-4-20.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 100001


bool vis[MAX];
int tin[MAX], low[MAX];
int timer;
vector<int> adj[MAX];
void dfs(int s, int p = -1) {
    vis[s] = true;

    tin[s] = low[s] = timer++;

    for(int to : adj[s]) {
        if(to == p) continue; // next node is parent do nothing

        if(vis[to]) low[s] = min(low[s], tin[to]); // if it is already visited then this cannot bridge as it is a back edge

        else {
            dfs(to, s);

            low[s] = min(low[s], low[to]);  // minimise current node source

            if(low[to] > tin[s]) { // this is bridge
                cout << to << " " << s << '\n';
            }
        }

    }
}

void find_bridges(int n) {
    timer = 0;
    memset(vis, false, MAX * sizeof(bool));
    memset(low, -1, MAX * sizeof(int));
    memset(tin, -1, MAX * sizeof(int));

    for(int i = 0; i < n; ++i) {
        if(!vis[i]) dfs(i);
    }
}

int main() {
    return 0;
}

