
// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/


bool vis[1001];


bool dfs(vector<int> adj[1001], int V, bool vis[1001], int s, int p) {

    vis[s] = true;

    for(int i = 0; i < adj[s].size(); ++i) {
        if(adj[s][i] == s) return true; // Self loop
        if(!vis[adj[s][i]]) {
            if(dfs(adj, V, vis, adj[s][i], s)) return true;
        }
        else {
            if(adj[s][i] != p) { // If a vertex is already visited (the only visited one can be the parent itself)
                return true;
            }
        }
    }

    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
    // Your code here
    for(int i = 0; i < V; ++i) {
        vis[i] = false;
    }
    bool flag = false;
    for(int i = 0; i < V; ++i) {
        if(!vis[i]) {
            flag = flag || dfs(adj, V,vis, i,  i);
        }
        if(flag) break;
    }

    return flag;

}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
// } Driver Code Ends*/
