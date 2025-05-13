#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N = 1e5 + 5;

vector<pair<int, int>> adj[MAX_N];
long long dist[MAX_N];
int ways[MAX_N], minStops[MAX_N], maxStops[MAX_N];

void dijkstra(int s) {
    fill(dist, dist + MAX_N, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[s] = 0, s});
    ways[s] = 1;
    minStops[s] = maxStops[s] = 0;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                ways[v] = ways[u];
                minStops[v] = minStops[u] + 1;
                maxStops[v] = maxStops[u] + 1;
            } else if (dist[v] == dist[u] + w) {
                ways[v] += ways[u];
                if (ways[v] >= M) ways[v] -= M;
                minStops[v] = min(minStops[v], minStops[u] + 1);
                maxStops[v] = max(maxStops[v], maxStops[u] + 1);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        from--; to--;
        adj[from].push_back({to, price});
    }
    dijkstra(0);

    cout << dist[n - 1] << " " << ways[n - 1] << " " << minStops[n - 1] << " " << maxStops[n - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
