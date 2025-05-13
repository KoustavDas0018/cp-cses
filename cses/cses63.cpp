#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll modularInverse(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = (res*a) % M;
            b = b-1;
        }
        else{
            a = (a * a) % M;
            b >>= 1;    
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll sum = (n*(n+1))/2;
    if(sum % 2 != 0){
        cout << 0;
        return 0;
    }
    //se in how many ways we can make sum / 2;
    sum = sum/2;
    vector<ll> prev(sum+1, 0);
    prev[0] = 1; //we can always make 0
    for(ll i = 1; i<= n; i++){
        vector<ll> curr(sum+1, 0);
        curr[0] = 1;
        for(ll j = 1; j<=sum; j++){
            //2 choices take or not take, see if we can make j using i
            
            curr[j] = (prev[j] + ((j-i >= 0)? prev[j-i]: 0)) % M;
        }
        prev = curr;
    } 
    //we counted 2 sets each time
    //cout << (prev[sum] / 2) % M; wrong we need modular multiplicative inverse
    //of 2  as (a/b) % M != (a % m) / (b % M)
    cout << (prev[sum] * modularInverse(2, M-2)) % M; // 2 ^ (M-2)
    return 0;
}