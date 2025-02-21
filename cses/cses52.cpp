#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> dp(n+1, LLONG_MAX);
    //min to reach n = 1 + min to reach(n-x)
    dp[0] = 0;
    for(ll i = 1; i<=n; i++){
        ll temp = i;
        while(temp > 0){
            ll lastDigit = temp%10;
            if(i-lastDigit >= 0 && dp[i-lastDigit] != LLONG_MAX){
                dp[i] = min(dp[i], 1+dp[i-lastDigit]);
            }    
            temp = temp/10;
        }
    }
    cout << dp[n];
    return 0;
}
