#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a;
    //sort as {end, start}
    for(ll i = 0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        a.push_back({y, x});
    }
    sort(a.begin(), a.end());
    //free multiset of k (endtime)
    multiset<ll> st;
    ll movie = 1;
    st.insert(a[0].first);
    for(ll i = 1; i<n; i++){
        auto it = st.upper_bound(a[i].second);
        if(it != st.begin()){
            it--;
            movie++;
            st.erase(it);
            st.insert(a[i].first);
        }
        else if(st.size()<k){
            st.insert(a[i].first);
            movie++;
        }
    }
    cout << movie;
    return 0;
}
