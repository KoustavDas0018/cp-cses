#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll starting, ending;//global
 
bool dfs(ll node, ll par, vector<ll> &vis, vector<vector<ll>> &adj, vector<ll> &parent){
    vis[node] = 1;
    parent[node] = par;
    for(auto it: adj[node]){
        //not visited
        if(vis[it] == 0){
            if(dfs(it, node, vis, adj, parent) == true){
                return true;
            }
        }
        //visited
        else if(it != par){ //cycle
            starting = it;//imp: strt and end
            ending = node;
            return true;
        }
    }
    return false;
}

bool isCycle(ll n, vector<ll> &vis, vector<vector<ll>> &adj, vector<ll> &parent){
    for(ll i = 1; i<=n; i++){
        if(vis[i] == 0){ //start -1 as parent
            if(dfs(i, -1, vis, adj, parent) == true) return true;
        }
    }
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    vector<ll> vis(n+1, 0); // n nodes
    vector<ll> parent(n+1, -1);
    while(m--){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag = isCycle(n, vis, adj, parent);
    if(flag){
        vector<ll> ans;
        while (ending != starting) {
            ans.push_back(ending);
            ending = parent[ending];
        }
        ans.push_back(starting);
        ans.push_back(ans[0]);// to complete the cycle
        cout << ans.size() << endl;
        for(ll i = 0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
    else cout << "IMPOSSIBLE";
    return 0;
}