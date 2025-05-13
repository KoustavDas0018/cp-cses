#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(const vector<vector<int>>& g, vector<bool>& visited, stack<int>& s){
    s.push(1);
    while(!s.empty()){
        int num = s.top();
        s.pop();
        visited[num] = true;
        for(int i : g[num]){
            if(!visited[i]){
                s.push(i);
            }
        }
    }
}

void solve(){
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj1(n + 1), adj2(n + 1);
    vector<bool> vis1(n + 1), vis2(n + 1);
    stack<int> s;
    while(m--){
        cin >> a >> b;
        adj1[a].pb(b);
        adj2[b].pb(a);
    }
    dfs(adj1, vis1, s);
    dfs(adj2, vis2, s);
    for(int i = 2; i <= n; i++){
        if(!vis1[i]){
            if(vis2[i]){
                cout << "NO" << endl << "1 " << i << endl;
            } 
            else{
                cout << "NO" << endl << "1 " << i << endl;
            }
            return;
        } 
        else if(!vis2[i]){
            cout << "NO" << endl << i << " 1" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(tc--){
        solve();
    }
    return 0;
}
