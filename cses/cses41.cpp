#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll count(vector<ll> &a, ll mid){
    ll cnt = 1;
    ll sum = 0;
    for(ll i = 0;  i<a.size(); i++){
        if(sum + a[i] <= mid) sum += a[i];
        else{
            cnt++;
            sum = a[i];
        }
    }
    return cnt;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0;  i<n; i++){
        cin >> a[i];
    }
    ll low = *max_element(a.begin(), a.end());
    ll high = accumulate(a.begin(), a.end(), 0ll);
    while(low <= high){
        ll mid = low + (high - low)/2;
        ll cnt = count(a, mid);
        if(cnt == k){
            high = mid - 1;
        }
        else if(cnt > k)    low = mid + 1;
        else    high = mid - 1;
    }
    cout << low;
    return 0;
}
