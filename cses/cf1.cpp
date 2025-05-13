#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    ll sum = 0ll;
    for(ll i = 0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum * k < x){
        cout << 0;
        return;
    }
    ll ans = 0;
    ll p = x / sum;
    sum = sum * p;
    for(ll i = n-1; i >= 0; i--){
        sum += a[i];
        if(sum >= x){
            ans = (i + 1) + (k - p - 1)*n;
            break;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}