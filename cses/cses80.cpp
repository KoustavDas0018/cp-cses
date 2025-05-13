#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int maxN = 2e5 + 1;
int n, m, a, b;
ll c, dist[2][maxN];
vector<pair<int, ll>> g[maxN];
priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> q;

void solve(){
    cin >> n >> m;
    fill(dist, dist + MAXN, LLONG_MAX);
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    dist[0][1] = dist[1][1] = 0;
    q.push({0, 1, 1});
    while(!q.empty()){
        ll d = get<0>(q.top());
        int u = get<1>(q.top());
        int coupon = get<2>(q.top());
        q.pop();

        if(dist[!coupon][u] < d)    continue;

        for(pair<int, ll> e : g[u]){
            int v = e.first;
            ll w = e.second;

            if(coupon){
                if(dist[0][v] > d + w){
                    dist[0][v] = d + w;
                    q.push({d+w, v, 1});
                }
                if(dist[1][v] > d + w/2){
                    dist[1][v] = d + w/2;
                    q.push({d+w/2, v, 0});
                }
            } else {
                if(dist[1][v] > d + w){
                    dist[1][v] = d + w;
                    q.push({d+w, v, 0});
                }
            }
        }
    }

    cout << min(dist[0][n], dist[1][n]) << endl;
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
