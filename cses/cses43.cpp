#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> a;
    //{arrival, departure}, index
    for(ll i = 0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        a.push_back({{x, y}, i});
    }
    //on basis of arrival
    sort(a.begin(), a.end());
    //set of departure, room allocated
    set<pair<ll, ll>> st;
    ll room = 1;
    vector<ll> ans(n);
    st.insert({a[0].first.second, room});
    ans[a[0].second] = room;
    //loop from 1
    for(ll i = 1; i<n; i++){
        //smallest deaprture check
        auto it = st.begin();
        ll dept = (*it).first;
        ll alloted = (*it).second;
        if(dept < a[i].first.first){
            //erase top {deptarture, alloted} set
            st.erase(it);
            st.insert({a[i].first.second, alloted});
            ans[a[i].second] = alloted;
        }
        else{
            room++;
            st.insert({a[i].first.second, room});
            ans[a[i].second] = room;
        }
    }
    cout << room << endl;
    for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
