/* Problem Link : https://www.spoj.com/problems/SUBMERGE/ */

// SUBMERGE - Submerging Islands

/* 
Vice City is built over a group of islands, with bridges connecting them. As anyone in Vice City knows, the biggest fear of vice-citiers is that some day the islands will submerge. The big problem with this is that once the islands submerge, some of the other islands could get disconnected. You have been hired by the mayor of Vice city to tell him how many islands, when submerged, will disconnect parts of Vice City. You should know that initially all the islands of the city are connected.

Input
The input will consist of a series of test cases. Each test case will start with the number N (1 ≤ N ≤ 10^4) of islands, and the number M of bridges (1 ≤ M ≤ 10^5). Following there will be M lines each describing a bridge. Each of these M lines will contain two integers Ui, Vi (1 ≤ Ui,Vi ≤ N), indicating that there is a bridge connecting islands Ui and Vi. The input ends with a case where N = M = 0.

Output
For each case on the input you must print a line indicating the number of islands that, when submerged, will disconnect parts of the city.

Example
Input:
3 3
1 2
2 3
1 3
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
0 0


Output:
0
1

*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void IS_CUTPOINT(int v, unordered_set<int>& cutPoints){
    cutPoints.emplace(v);
}

void dfs(vector<vector<int>>& adj, int v, vector<bool>& visited, vector<int>& tin, vector<int>& low, unordered_set<int>& cutPoints, int& timer, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for (int to : adj[v])
    {
        if (to == p)
            continue;

        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(adj, to, visited, tin, low, cutPoints,timer, p);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1)
                IS_CUTPOINT(v, cutPoints);
            ++children;
        }
    }

    if (p == -1 && children > 1)
        IS_CUTPOINT(v,cutPoints);
}

unordered_set<int> find_cutpoints(vector<vector<int>>& adj)
{
    int timer = 0;
    unordered_set<int> cutPoints;
    vector<bool> visited;
    vector<int> tin, low;
    int n = adj.size();
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);

    for (int i = 1; i < n; ++i){
        if (!visited[i])
            dfs(adj, i, visited, tin, low, cutPoints, timer);
    }

    return cutPoints;
}

int main() {
    
    int n, m, a, b;
    cin >> n >> m;

    while (n != 0 && m != 0){
        vector<vector<int>> adj;
        for (int i = 0; i <= n; ++i) {
            vector<int> temp;
            adj.push_back(temp);
        }

        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            adj[a].push_back(b);
        }

        

        unordered_set<int> ans = find_cutpoints(adj);
        cout << ans.size() << '\n';
        cin >> n >> m;
    }
    

    return 0;
}