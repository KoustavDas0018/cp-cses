#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i = 0;  i<n; i++){
        cin >> a[i];
    }
    map<ll, ll> mpp;
    ll presum = 0;
    mpp[presum] = 1;
    ll cnt = 0;
    for(ll i = 0;  i<n; i++){
        presum += a[i];
        ll rem = presum - x;
        cnt += mpp[rem];
        mpp[presum]++;
    }
    cout << cnt;
    return 0;
}
