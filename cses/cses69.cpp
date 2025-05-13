#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//message route
int n, m;
vector<vector<int>> g;
vector<int> par;
vector<bool> vis;
void bfs(){
	vis[1] = true;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v: g[u]){
			if(!vis[v]){
				vis[v] = true;
				par[v] = u;
				q.push(v);
			}
		}
	} 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	par.resize(n+1);
	for(int i = 0; i<=n; ++i){
		par[i] = -1;
	}
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	if(par[n] == -1){
		cout <<  "IMPOSSIBLE";
		return 0;
	}
	int candidate = n;
	stack<int> stk;
	while(candidate != -1){
		stk.push(candidate);
		candidate = par[candidate];
	}
	cout << stk.size() << endl;
	while(!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
	return 0;
 }