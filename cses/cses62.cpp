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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    vector<ll> temp;
    temp.push_back(a[0]);
    //find suitable position for the element to be inserted
    //see where it fits, if it fits in and length not increase means 
    //it doesn't contribute for a longer subsequence
    for(ll i = 1; i<n; i++){
        ll ind = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
        if(ind == temp.size())  temp.push_back(a[i]);
        else    temp[ind] = a[i];
    }
    cout << temp.size();
    return 0;
}