#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N = 1e5 + 1;
vector<int> parent(MAX_N), rank(MAX_N);
int compCount, compSize;

int Find(int x){
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int u = Find(x);
    int v = Find(y);
    if (u == v) return;

    if(rank[u] < rank[v]){
        swap(u, v);
    }

    parent[v] = u;
    rank[u] += rank[v];

    compCount--;
    compSize = max(compSize, rank[u]);
}

void solve(){
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    rank.resize(n + 1);
    compCount = n;
    compSize = 1;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        rank[i] = 1;
    }
    while(m--){
        int u, v;
        cin >> u >> v;
        Union(u, v);
        cout << compCount << " " << compSize << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
