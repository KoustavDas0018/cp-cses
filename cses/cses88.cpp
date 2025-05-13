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
struct Edge {
    int u, v, w;
};
int parent[MAX_N];
int Find(int x){
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool compareEdges(const Edge& a, const Edge& b){
    return a.w < b.w;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; ++i){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(all(edges), compareEdges);
    ll result = 0;
    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int num_edges = 0;
    for(const auto& edge : edges){
        int u = Find(edge.u);
        int v = Find(edge.v);
        if (u != v){
            result += edge.w;
            parent[v] = u;
            ++num_edges;
            if (num_edges == n - 1){
                break; // Minimum spanning tree formed
            }
        }
    }
    if(num_edges != n - 1){
        cout << "IMPOSSIBLE" << endl;
    } 
    else{
        cout << result << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1; 
    // cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}
