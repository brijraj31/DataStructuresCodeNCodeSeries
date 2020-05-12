#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001

int level[MAXN];

vector<int> adj[MAXN];
bool vis[MAXN];
int parent[MAXN];
void dfs(int s = 1, int l = 0, int par = -1) {
    level[s] = l;
    vis[s] = true;
    parent[s] = par;
    for(int x : adj[s]) {
        if(!vis[x]) {
            dfs(x , l + 1, s);
        }
    }
}
void initLevel() {
    memset(vis, false, MAXN * sizeof(vis));
    dfs();
}

int main() {

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 

    initLevel();


    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        int la = level[a];
        int lb = level[b];

        if(la < lb) {
            while(lb != la) {
                b = parent[b];
                lb --;
            }
        }
        else if(la > lb) {
            while(lb != la) {
                a = parent[a];
                la --;
            }
        }

        while(a != b) {
            a = parent[a];
            b = parent[b];
        }

        cout << a << '\n';
    }
    return 0;
}