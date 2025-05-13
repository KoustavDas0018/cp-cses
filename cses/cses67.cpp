#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
bool dfs(ll node, ll col, vector<ll> &colour, vector<vector<ll>> &adj){
    colour[node] = col;
    for(auto it: adj[node]){
        if(colour[it] == -1){
            if(dfs(it, !col, colour, adj) == false){
                return false;
            }
        }
        else if(colour[it] == colour[node]) return false;
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    vector<ll> colour(n+1, -1); // n nodes
    while(m--){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag = true;
    for(ll i = 1; i<=n; i++){
        if(colour[i] == -1){
            if(dfs(i, 0, colour, adj) == false) flag = false; //colour with 0,1
        }
    }
    if(flag){
        //for 0 print team 1, for 1 print team 2
        for(ll i = 1; i<=n; i++){
            if(colour[i] == 0)  cout << 1 << " ";
            else cout << 2 << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
    return 0;
}