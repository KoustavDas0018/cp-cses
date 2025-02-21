#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(ll i = 0; i<n-1; i++){
        if(a[i] > a[i+1]){
            ans += (a[i] - a[i+1]);
            a[i+1] = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}