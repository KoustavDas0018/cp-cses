#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<string> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    //if start or end is trap then no way
    if(a[0][0] == '*' || a[n-1][n-1] == '*'){
        cout << 0;
        return 0;
    }
    //otherwise if reaches 0,0 then 1
    dp[0][0] = 1;
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            //to i,j = to reach (i-1,j) + to reach (i,j-1)
            //make sure its not a trap. if trap then no way to reach here
            if(a[i][j] != '*'){
                if(i-1 >= 0)    dp[i][j] = (dp[i][j] + dp[i-1][j]) % M;
                if(j-1 >= 0)    dp[i][j] = (dp[i][j] + dp[i][j-1]) % M;
            }
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}
