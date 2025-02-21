#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a;
    //sort as {end, start}
    for(ll i = 0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        a.push_back({y, x});
    }
    sort(a.begin(), a.end());
    ll movie = 1;
    ll lastend = a[0].first;
    for(ll i = 1; i<n; i++){
        if(a[i].second >= lastend){
            movie++;
            lastend = a[i].first;
        }
    }
    cout << movie;
    return 0;
}
