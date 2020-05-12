// Problem Link https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0


#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAXN 10001
vector<pair<int, int>> adj[MAXN];
#define pb push_back
#define eb emplace_back
#define mp make_pair



int main() {

    for(int i = 1; i < MAXN; ++i) {
        if(i + 1 < MAXN) {
            adj[i].eb(i + 1, 1);
        }
        if(i * 3 < MAXN) {
            adj[i].eb(i * 3 , 1);
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;

    vector<int> dist(MAXN, INT_MAX);

    pq.push(mp(0,1));

    dist[1] = 0;

    while(!pq.empty()) {

        int curr = pq.top().second;
        int curr_d = pq.top().first;

        pq.pop();

        for(pair<int, int> edge : adj[curr]) {
            if(curr_d + edge.second < dist[edge.first]) {
                dist[edge.first] = curr_d + edge.second;
                pq.emplace(dist[edge.first], edge.first);
            }
        }
    }


    int t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        cout << dist[x] << '\n';
    }
    return 0;
}