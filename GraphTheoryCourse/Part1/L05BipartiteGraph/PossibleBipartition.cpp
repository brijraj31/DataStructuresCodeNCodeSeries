// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/

// Possible Bipartition

/* Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j]. */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool dfs(vector<vector<int>>& g, vector<bool>& vis, int s, int c, vector<bool> col) {
        vis[s] = true;
        col[s] = c;
        
        for (int i = 0; i < g[s].size(); ++i) {
            if (!vis[g[s][i]]) {
                if (!dfs(g, vis, i, ~c, col)) {
                    return false;
                }
            }
            else if (col[s] == col[g[s][i]]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        vector<bool> vis;
        vector<bool> col;
        for (int i = 0; i < g.size(); ++i) {
            vis.push_back(false);
            vis.push_back(false);
        }
        
        return dfs(g, vis, 0, 0, col);
        
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> g;
        for (int i = 0; i <= N; ++i) {
            vector<int> temp;
            g.push_back(temp);
        }
        for (auto x : dislikes) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        
        return isBipartite(g);
    }
};


int main() {
    int size;
    cin >> size;

    vector<vector<int>> vect;

    for (int i = 0; i < size; ++i) {
        int a, b;
        cin >> a >> b;

        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        vect.push_back(temp);
    }

    Solution s;
    cout << s.possibleBipartition(size, vect);
}