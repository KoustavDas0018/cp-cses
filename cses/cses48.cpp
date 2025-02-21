#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> dp(n+1, 0);
    //dp[n] find, only if we reach 0 then it is valid
    dp[0] = 1;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=6; j++){
            if(i-j >= 0){
                dp[i] = ((dp[i] + dp[i-j]) % M);
            }
        }
    }
    cout << dp[n];
    return 0;
}
