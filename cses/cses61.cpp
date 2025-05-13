#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    //dp[i][j] = max point of player from i to j array
    //base case : if i == j and j - i == 1
    vector<vector<ll>> dp(n, vector<ll> (n, LLONG_MAX)); 
    //as we take min so initialize with max
    for(ll i = 0; i<n; i++){
        dp[i][i] = a[i];
    }
    for(ll i = 0; i<n-1; i++){
        dp[i][i+1] = max(a[i], a[i+1]);
    }
    //from small to bigger sub problem so start from a[n-3].. a[n-1]
    for(ll i = n-3; i>=0; i--){ //from n-3 to 0
        for(ll j = i+2; j<n; j++){ // j from i+2 length = 2
            // from a[i], a[i+1], a[i+2] .... a[j-2] ,a[j-1], a[j]
            //if player 1 will choose a[i] so, player2 will choose either
            //a[i+1] or a[j] so that player 1 gets minimum points
            ll choice1 = a[i] + min(dp[i+2][j], dp[i+1][j-1]);
            //if player 2 will choose a[j] so, player2 will choose either
            //a[i] or a[j-1] so that player 1 gets minimum points
            ll choice2 = a[j] + min(dp[i+1][j-1], dp[i][j-2]);
            //take maximum of 2 coices for player 1
            dp[i][j] = max(choice1, choice2);
        }
    }
    cout << dp[0][n-1];
    return 0;
}