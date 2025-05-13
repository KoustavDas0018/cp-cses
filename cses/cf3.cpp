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
    ll n, x;
    cin >> n >> x;
    vector<ll> a;
    
    //a[i] must be submask of x, x ke bit jahan 0 hai a[i] ke 0 hi hoga
    //(a[i] | x == x)
    //the moment we get a submask ! x it will bb the mex
    //check if first n-1 elements xor = x or not. if not then it must contain
    //x in end otherwise fill from 0 and go on
    ll xorr = 0;
    for(ll i = 0; i<n-1; i++){
        if((i | x) == x){
            a.push_back(i);
            xorr = (xorr ^ i);
        }
        else{
            ll last = a.back();
            a.push_back(last);
            xorr = (xorr ^ last);
        }
    }
    if(xorr == x)   a.push_back(a.back()+1);
    else    a.push_back(x);
    for(ll i = 0; i<n; i++){
        cout << a[i] << " ";
    }
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