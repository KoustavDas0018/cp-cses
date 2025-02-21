#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0;  i<n; i++){
        cin >> a[i];
    }
    //(x-y)%n = k means x%n = y%n
    //all remainder must be positive
    //-2 % 6 = (-2+6) % 6 = 4 % 6
    map<ll, ll> mpp;
    ll presum = 0;
    mpp[0] = 1;
    ll cnt = 0;
    for(ll i = 0;  i<n; i++){
        presum += a[i];
        ll toBeStored = presum % n;
        if(toBeStored < 0)  toBeStored = toBeStored + n;
        mpp[toBeStored]++;
    }
    for(auto it : mpp){
        ll m = it.second;
        if(m >= 2){
            cnt += (m*(m-1)/2);
        }
    }
    cout << cnt;
    return 0;
}
