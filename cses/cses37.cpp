#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i = 1;  i<=n; i++){
        cin >> a[i];
    }
    //monotonic stack
    stack<pair<ll, ll>> s;
    for(ll i = 1;  i<=n; i++){
        while(s.size() && a[i] <= s.top().first){
            s.pop();
        }
        if(s.size())    cout << s.top().second << " ";
        else cout << 0 << " ";
        s.push({a[i], i});
    }
    return 0;
}
