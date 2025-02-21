#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
 
//imp: long long was not necessarily wrong but less efficient
// in terms of memory usage, leading to potential runtime errors with large constraints.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }
    //[n][x+1] 0 1 knapsack
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    //base case index = 0
    for(int i = a[0]; i<=x; i++){
        dp[0][i] = b[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=x; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(j-a[i] >= 0) take = b[i] + dp[i-1][j-a[i]];
            dp[i][j] = max(take, notTake);
        }
    }
    cout << dp[n-1][x];
    return 0;
}