#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    map<ll, ll> mpp;
    for(ll i = 0; i<n; i++){
        ll num = a[i];
        ll needed = x - num;
        if(mpp.find(needed) != mpp.end()){
            cout << i+1 << " " << mpp[needed];
            return 0;
        }
        mpp[a[i]] = i+1;
    }
    cout << "IMPOSSIBLE";
    return 0;
}