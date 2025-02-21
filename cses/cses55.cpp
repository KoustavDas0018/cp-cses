#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    //[ind][1...m] 
    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
    //check if 0 or any regular number
    //base case index = 0
    if(a[0] == 0){
        for(ll i = 1; i<=m; i++){
            dp[0][i] = 1;
        }
    }
    else    dp[0][a[0]] = 1;
    for(ll i = 1; i<n; i++){
        if(a[i] == 0){ // means update from 
            for(ll j = 1; j<=m; j++){
                //j-x  = 1- to 1
                if(j-1 >= 0)    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % M;
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % M;
                if(j+1 <= m)    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % M;
            }            
        }
        else{// a[i] != 0 -> all others from 1 to m will be 0 
            ll j = a[i];
            if(j-1 >= 0)    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % M;
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % M;
            if(j+1 <= m)    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % M;
        }
    }
    //ans loop needed bcz what if a[n-1] = 0
    ll ans = 0;
    for(ll j = 1; j<=m; j++){
        ans = (ans + dp[n-1][j]) % M;
    }
    cout << ans;
    return 0;
}