#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long LLINF = LLONG_MAX;
int INF = INT_MAX;
int MOD = 1e9 + 7;
void dfs(int u, vector<vector<int>>& adj, vector<int>& dp, vector<int>& nextNode, vector<bool>& visited, int n){
    dp[u] = (u == n - 1) ? 1 : -1e9;
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v, adj, dp, nextNode, visited, n);
        if(dp[u] < dp[v] + 1){
            dp[u] = dp[v] + 1;
            nextNode[u] = v;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
    }
    vector<int> dp(n), nextNode(n, -1);
    vector<bool> visited(n);
    dfs(0, adj, dp, nextNode, visited, n);
    if(dp[0] > 0){
        cout << dp[0] << endl;
        for(int u = 0; u != -1; u = nextNode[u]){
            cout << u + 1 << " ";
        }
        cout << endl;
    } 
    else  cout << "IMPOSSIBLE" << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
