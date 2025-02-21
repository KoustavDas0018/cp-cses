#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    ll m = a.length();
    ll n = b.length();
    //dp[i][j] = a ke i character , b ke j characters match le liye
    vector<vector<ll>> dp(m+1, vector<ll>(n+1, 0));
    //base case:0 characters left in any string(remove all character from other)
    for(ll i = 0; i<=n; i++){ //0 in string a
        dp[0][i] = i;
    }
    for(ll i = 0; i<=m; i++){ // 0 in string b
        dp[i][0] = i;
    }
    //start from 1 character
    for(ll i = 1; i<=m; i++){
        for(ll j = 1; j<=n; j++){
            //if matches then no operation needed (1 indexed)  a[i-1] == b[j-1]
            if(a[i-1] == b[j-1])    dp[i][j] = dp[i-1][j-1];
            else{
                ll choice1 = 1 + dp[i-1][j-1]; //replacing ith or jth character
                ll choice2 = 1 + dp[i-1][j]; // remove ith or add after jth
                ll choice3 = 1 + dp[i][j-1]; //remove jth or add after ith
                dp[i][j] = min(choice1, min(choice2, choice3));
            }
        }
    }
    cout << dp[m][n];
    return 0;
}