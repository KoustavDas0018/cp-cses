#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b; // a = length, b = height
    cin >> a >> b;
    vector<vector<ll>> dp(a+1, vector<ll>(b+1, LLONG_MAX));
    //dp[i][j] = up to i*j rectangle
    //base case : if reaches a square
    for(ll i = 1; i<=min(a, b); i++){
        dp[i][i] = 0;
    }
    for(ll i = 1; i<=a; i++){
        for(ll j = 1; j<=b; j++){
            //horizontal cuts
            for(ll k = 1; k<= j-1; k++){ 
                if(j-k >= 0)  dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }
            //vertical cuts
            for(ll k = 1; k<= i-1; k++){ 
                if(i-k >= 0)  dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }
        }
    }
    cout << dp[a][b];
    return 0;
}