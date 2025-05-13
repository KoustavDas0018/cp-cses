#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define m (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll nmax = 1e5 + 5;
vector<pair<ll, ll>> adj[nmax];
priority_queue<ll> dist[nmax];

void dijkstra(ll start, ll k){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[start].push(0);
    pq.push({0, start});
    while(!pq.empty()){
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if(d > dist[u].top()) continue;
        for(auto &[v, w] : adj[u]){
            ll to = d + w;
            if(dist[v].size() < k){
                dist[v].push(to);
                pq.push({to, v});
            }
            else if(dist[v].top() > to){
                dist[v].push(to);
                while(dist[v].size() > k) dist[v].pop();
                pq.push({to, v});
            }
        }
    }
}

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        ll from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
    }
    dijkstra(1, k);
    vector<ll> result;
    while(dist[n].size()){
        result.push_back(dist[n].top());
        dist[n].pop();
    }
    reverse(result.begin(), result.end());
    for(ll x : result)
        cout << x << ' ';
    cout << endl;
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
