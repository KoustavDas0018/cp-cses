#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
void dfs(ll node, vector<vector<ll>> &adj, vector<ll> &vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it] == 0)    dfs(it, adj, vis);
    }
}
 
void connected_components(ll n, vector<vector<ll>> &adj, vector<ll> &vis, vector<ll> &unique){
    for(ll i = 1; i<=n; i++){
        if(vis[i] == 0){
            unique.push_back(i);
            dfs(i, adj, vis);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    vector<ll> vis(n+1, 0); // n nodes
    vector<ll> unique; // to store only one vertice from a component
    while(m--){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //connected components - 1 and all adjacent values
    connected_components(n, adj, vis, unique);
    cout << unique.size()-1 << endl;
    for(ll i = 0; i<unique.size()-1; i++){
        cout << unique[i] << " " << unique[i+1] << endl;
    }
    return 0;
}