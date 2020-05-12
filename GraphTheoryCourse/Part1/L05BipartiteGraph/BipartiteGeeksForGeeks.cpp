
// { Driver Code Starts
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
    cin>>t;
    int g[MAX][MAX];
    while(t--)
    {
        memset(g,0,sizeof (g));
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>g[i][j];
            }
        }

        cout<<isBipartite(g,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

bool vis[MAX];
int col[MAX];
bool dfs(int G[][MAX], int V, bool vis[MAX], int s, int c, int col[MAX]) {
    vis[s] = true;
    col[s] = c;
    for(int i = 0; i < V; ++i) {
        if(G[s][i]) {
            if(!vis[i]) {
                if(!dfs(G, V, vis, i, c ^ 1, col)) {
                    return false;
                }
            }
            else if(col[s] == col[i]) return false;
        }
    }
    return true;
}
bool isBipartite(int G[][MAX],int V)
{

    for(int i = 0; i < V; ++i) {
        vis[i]= false;
        col[V] = 0;
    }

    return dfs(G,V,vis,0,0,col);


    //Your code here
}
