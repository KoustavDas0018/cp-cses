#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define m (ll)(1e9 + 7)

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    vector<int> order;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }

    if(order.size() == n){
        for(int x : order){
            cout << x << " ";
        }    
        cout << endl;
    }
    else    cout << "IMPOSSIBLE" << endl;
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
