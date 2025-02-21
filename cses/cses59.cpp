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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    //ordered set
     //ordered set -> doesn't include repeating values,so play with index(pair)
    ordered_set<pair<ll, ll>> ost;
    for(ll i = 0; i<k; i++){
        ost.insert({a[i], i});
    }
    cout << (*ost.find_by_order((k-1)/2)).first << " ";
    //remove the front and add in back
    for(ll i = k; i<n; i++){
        ost.erase({a[i - k], i-k}); 
        ost.insert({a[i], i});  
        cout << (*ost.find_by_order((k-1)/2)).first << " ";
    }
    return 0;
}