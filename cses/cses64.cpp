#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool cmp(pair<pair<ll, ll>, ll> &x, pair<pair<ll, ll>, ll> &y){
    return x.first.second < y.first.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    //imp: 1 based indexing
    vector<pair<pair<ll, ll>, ll>> a(n+1); //{{start, end}, reward}
    vector<ll> ends(n+1); // make a array of endpoints (1 based)
    ends[0] = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        ends[i] = a[i].first.second;
    }
    sort(a.begin()+1, a.end(), cmp); // on basis of end date(1 based)
    sort(ends.begin(), ends.end());
    //dp[i] = upto ith(1based) preject max reward
    vector<ll> dp(n+1, 0);
    dp[0] = 0; //base case no projects left
    //start from 1st preject to nth project
    for(ll i = 1; i<=n; i++){ 
        ll notTake = 0 + dp[i-1];
        ll take = a[i].second;
        //find a project s.t end[j] < start of i
        //first find lower bound then go -1
        ll j = lower_bound(ends.begin(), ends.end(), a[i].first.first) - ends.begin();
        j--;
        if(j >= 1)  take += dp[j];
        dp[i] = max(notTake, take);
    }
    cout << dp[n];
    return 0;
}