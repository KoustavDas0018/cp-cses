#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    ll maxi = LLONG_MIN;
    ll sum = 0;
    for(ll i = 0; i<n; i++){
        sum += a[i];
        maxi = max(sum, maxi);
        if(sum < 0) sum = 0;
    }
    cout << maxi;
    return 0;
}
