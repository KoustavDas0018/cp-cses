#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0;  i<n; i++){
        cin >> a[i];
    }
    ll cnt = 0;
    ll i = 0, j = 0;
    map<ll, ll> mpp;
    for(j = 0; j<n; j++){
        mpp[a[j]]++;
        while(mpp.size() > k){
            mpp[a[i]]--;
            if(mpp[a[i]] == 0)  mpp.erase(a[i]);
            i++;
        }
        cnt += (j-i+1);
    }
    cout << cnt;
    return 0;
}
