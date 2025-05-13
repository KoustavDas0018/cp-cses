#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 1e3 + 5;
ll d[N][N];
void floyd_warshal(int n){
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j) continue;
            d[i][j] = 223372036854775807;
        }
    }

    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    floyd_warshal(n);

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if(d[u][v] == 223372036854775807){
            cout << -1 << endl;
        }
        else{
            cout << d[u][v] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    // cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}
