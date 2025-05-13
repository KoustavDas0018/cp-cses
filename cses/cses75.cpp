#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int MOD = 1e9 + 7;
int INF = 1e9;
ll LLINF = 1e18;
int N = 2e5 + 1;
int BIT = 2 * N;

struct Interval{
    int l, r, idx;
};
void update(int i, int v, vector<int>& b){
    for(; i < BIT; i += -i & i)
        b[i] += v;
}
int query(int i, vector<int>& b){
    int c = 0;
    for(; i > 0; i -= -i & i)
        c += b[i];
    return c;
}

void solve(){
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    set<int> uniqueEndpoints;
    map<int, int> endpointToIndex;
    for(int i = 0; i < n; i++){
        cin >> intervals[i].l >> intervals[i].r;
        intervals[i].idx = i;
        uniqueEndpoints.insert(intervals[i].l);
        uniqueEndpoints.insert(intervals[i].r);
    }
    sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
        return (a.l == b.l ? a.r > b.r : a.l < b.l);
    });
    int index = 1;
    for(int endpoint : uniqueEndpoints)
        endpointToIndex[endpoint] = index++;
    vector<int> bit(BIT, 0);
    vector<vector<int>> ans(2, vector<int>(n, 0));
    for(int i = n - 1; i >= 0; i--){
        int upperEndpoint = endpointToIndex[intervals[i].r];
        int rangeIndex = intervals[i].idx;
        ans[0][rangeIndex] = query(upperEndpoint, bit);
        update(upperEndpoint, 1, bit);
    }
    for(int i = 0; i < BIT; i++)
        bit[i] = 0;
    for(int i = 0; i < n; i++){
        int upperEndpoint = endpointToIndex[intervals[i].r];
        int rangeIndex = intervals[i].idx;
        ans[1][rangeIndex] = i - query(upperEndpoint - 1, bit);
        update(upperEndpoint, 1, bit);
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j];
            if(j == n - 1)
                cout << endl;
            else
                cout << ' ';
        }
    }
}

int main(){
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
