#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 4;

class Solution {
public:
    ll shortestPath(int n, int a, int b, vector<vector<int>>& edges) {

        vector<vector<pair<int, pair<ll, ll>>>> adj(n + 1);

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            ll w1 = edge[2], w2 = edge[3];
            adj[u].push_back({v, {w1, w2}});
            adj[v].push_back({u, {w1, w2}});
        }

        vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));

        using T = pair<ll, pair<int, int>>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[a][0] = 0;
        pq.push({0, {a, 0}});

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ll d = top.first;
            int u = top.second.first;
            int used = top.second.second;

            if (d > dist[u][used]) continue;

            for (auto &nb : adj[u]) {
                int v = nb.first;
                ll straight = nb.second.first;
                ll curved = nb.second.second;

                if (dist[u][used] + straight < dist[v][used]) {
                    dist[v][used] = dist[u][used] + straight;
                    pq.push({dist[v][used], {v, used}});
                }

                if (used == 0 && dist[u][0] + curved < dist[v][1]) {
                    dist[v][1] = dist[u][0] + curved;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
        }

        ll ans = min(dist[b][0], dist[b][1]);
        return ans >= INF ? -1 : ans;
    }
};
