#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    vector<ll> dp(x+1, 0);
    //only if we reach 0 then it is valid combination
    //first use all 2's then use all 3's then 5's then see if you reached destination
    dp[0] = 1;
    //sum all combinations
    for(ll j = 0; j<n; j++){
        for(ll i = 1; i<=x; i++){
            if(i-a[j] >= 0){
                dp[i] = (dp[i] + dp[i-a[j]]) % M;
            }
        }
    }
    cout << dp[x];
    return 0;
}
