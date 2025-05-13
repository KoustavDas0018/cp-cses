#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<int> dp(n, 0);
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
        dp[u] = (u == n - 1) ? 1 : 0;
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) 
                dfs(v);
            dp[u] += dp[v];
            if (dp[u] >= M) 
                dp[u] -= M;
        }
    };
    dfs(0);
    
    cout << dp[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
