#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(ll row, ll col, ll n, ll m, vector<vector<char>> &a, vector<vector<ll>> &vis){
    vis[row][col] = 1;
    vector<ll> dx{-1, 0 , 0, 1};
    vector<ll> dy{0, -1 , 1, 0};
    for(ll i = 0; i<4; i++){
        ll nrow = row + dx[i];
        ll ncol = col + dy[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && a[nrow][ncol] == '.'){
            dfs(nrow, ncol, n, m, a, vis);
        }
    }
}

ll connected_components(ll n, ll m, vector<vector<char>> &a, vector<vector<ll>> &vis){
    ll rooms = 0;
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            if(vis[i][j] == 0 && a[i][j] == '.'){
                dfs(i, j, n, m, a, vis);
                rooms++;
            }
        }
    }
    return rooms;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<char>>a(n, vector<char>(m));
    vector<vector<ll>>vis(n, vector<ll>(m, 0));
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }
    cout << connected_components(n, m, a, vis);
    return 0;
}