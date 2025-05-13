#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define m (ll)(1e9 + 7)

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2501;
const int maxm = 5001;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge{
    int a, b;
    ll c;
}edges[maxm];

int n, m, ptr, p[maxn];
ll dp[maxn];

void solve(){
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++){
        ll c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    ptr = -1;
    fill(dp + 2, dp + n + 1, inf);
    for(int iter = 0; iter < n && ptr; iter++){
        ptr = 0;
        for(int i = 0; i < m; i++){
            int u = edges[i].a;
            int v = edges[i].b;
            ll w = edges[i].c;

            if(dp[v] > dp[u] + w){
                dp[v] = dp[u] + w;
                p[v] = u;
                ptr = v;
            }
        }
    }
    if(!ptr){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < n; i++)
        ptr = p[ptr];

    vector<int> cycle;
    for(int v = ptr;; v = p[v]){
        cycle.push_back(v);
        if(v == ptr && (int)cycle.size() > 1)
            break;
    }
    reverse(cycle.begin(), cycle.end());
    cout << "YES" << endl;
    for(int i = 0; i < cycle.size(); i++)
        cout << cycle[i] << (i == cycle.size() - 1 ? '\n' : ' ');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
