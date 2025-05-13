#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define m (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 1e5 + 1;
int n, m, start, finish, p[maxn], vis[maxn];
vector<int> ans, g[maxn];

void dfs(int u){
    vis[u] = 1;
    for(int v : g[u]){
        if(vis[v] == 0){
            p[v] = u;
            dfs(v);
            if(start) return;
        }
        else if(vis[v] == 1){
            finish = u;
            start = v;
            return;
        }
    }
    vis[u] = 2;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= n && !start; i++){
        if(vis[i] == 0)
            dfs(i);
    }
    if(!start){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    ans.push_back(start);
    for(int u = finish; u != start; u = p[u]){
        ans.push_back(u);
    }
    ans.push_back(start);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
