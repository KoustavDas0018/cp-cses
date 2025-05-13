#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Edge{
    int u, v;
    ll w;
};

vector<Edge> edges;
vector<int> forward_adj[2501], reverse_adj[2501];
bool visited_forward[2501], visited_reverse[2501];

void dfs(int node, bool* visited, vector<int>* adj){
    visited[node] = true;
    for(int neighbor : adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor, visited, adj);
        }
    }
}

ll shortestPath(int n, int m){
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    for(int i = 0; i < n; i++){
        for(const Edge& edge : edges){
            int u = edge.u;
            int v = edge.v;
            ll w = edge.w;

            if(dist[u] != LLONG_MAX && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;

                if(i == n - 1 && visited_forward[v] && visited_reverse[v]){
                    return -1;
                }
            }
        }
    }
    return -dist[n];
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, -w});
        forward_adj[u].push_back(v);
        reverse_adj[v].push_back(u);
    }
    dfs(1, visited_forward, forward_adj);
    dfs(n, visited_reverse, reverse_adj);
    ll result = shortestPath(n, m);
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
