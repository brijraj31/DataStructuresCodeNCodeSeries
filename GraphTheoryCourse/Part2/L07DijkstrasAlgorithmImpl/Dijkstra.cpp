#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[1001];
#define mp make_pair
#define eb emplace_back
#define INF 1000000001
int main() {

    int n, m, a, b, w;

    cin >> n >> m;

    while (m --) {
        cin >> a >> b >> w;
        adj[a].eb(b, w);
        adj[b].eb(a, w);
    }

    priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, INF);

    pq.emplace(0,1);
    dist[1] = 0;


    while (!pq.empty()) {
        int curr = pq.top().second;
        int curr_d = pq.top().first;

        pq.pop();

        for (pair<int, int> edge : adj[curr]) {
            if (curr_d + edge.second < dist[edge.first]) {
                pq.emplace(dist[edge.first] , edge.first);
            }
        }
    }
    return 0;
}