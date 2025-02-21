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
    vector<ll> dp(x+1, LLONG_MAX);
    //0 to 0 by 0 coins(only if we reach 0 means we are in a correct comination)
    //dp[any smallest coin] = dp[0] + 1
    dp[0] = 0;
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    for(ll i = 1; i<=x; i++){
        for(ll j = 0; j<n; j++){
            if(i-a[j] >= 0 && dp[i-a[j]] != LLONG_MAX){
                dp[i] = min(dp[i], dp[i-a[j]]+1);
            }
        }
    }
    if(dp[x] == LLONG_MAX)  cout << -1;
    else    cout << dp[x];
    return 0;
}
