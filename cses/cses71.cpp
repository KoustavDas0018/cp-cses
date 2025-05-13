#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m;
vector<vector<pair<ll,ll>>> g;
vector<ll> dist;
const ll maxi = 1e17;
 
void dijkstra(){
	for(ll i = 0; i <= n; ++i){
		dist[i] = maxi;
	}
 
	priority_queue<pair<ll,ll>, 
	vector<pair<ll,ll>>, 
	greater<pair<ll,ll>> > pq;
	dist[1] = 0;
	pq.push({0,1});
	while(!pq.empty()){
		ll u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if(dist[u] < d) continue;
		for(auto e: g[u]){
			ll v = e.first;
			ll c = e.second;
			if(dist[v] <= c+d) continue;
			else{
				dist[v] = c+d;
				pq.push({dist[v], v});
			}
 
		}
	}
 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	dist.resize(n+1);
	for(auto i = 0; i < m; ++i){
		ll u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	dijkstra();
	for(ll i = 1; i <=n; ++i ){
		cout << dist[i] << " ";
	}
    return 0;
}