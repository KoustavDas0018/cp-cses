#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n+1);
    //prefix sum array(1 bassed)
    vector<ll> presum(n+1, 0);
    for(ll i = 1; i<=n; i++){
        cin >> arr[i];
        presum[i] = presum[i-1] + arr[i];
    }
    //multiset, may be repetatiave values
    multiset<ll> ms;
    //add from a to b indexed
    for(ll i = a; i<=b; i++){
        ms.insert(presum[i]);
    }
    //presum[a-1]-presum[b] = subarray sum from
    // a to b index
    //take the maximum value from ms and take what to be subtracted 
    //then erase a value insert new one like sliding windew of length(b-a+1)
    ll ans = LLONG_MIN;
    ll i = 1;
    //at last i+a-1 only will be there to remove
    //so i+a-1 = last index = n 
    for(ll i = 1; i+a-1<=n; i++){
        ll maxinSet = *(ms.rbegin());
        ll subarrSum = maxinSet - presum[i-1];
        ans = max(ans, subarrSum);
        ms.erase(ms.find(presum[i+a-1]));
        if(i+b <= n)  ms.insert(presum[i+b]);
    }
    cout << ans;
    return 0;
}
