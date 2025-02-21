#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i = 0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> prev(sum + 1, 0);
    //base case -> we can reach 0
    //0 can't reach, 1 -> can reach
    prev[0] = 1;
    set<ll> st;
    for(ll i = 0; i<n; i++){
        //each time curr must be 0 initialized, and curr[0] must be 1
        //otherwise when prev = curr, prev[0] becomes 0
        vector<ll> curr(sum + 1, 0);
        curr[0] = 1;
        for(ll j = 1; j<=sum; j++){ 
        //check if we have the value j previously or can get j after adding a[i]
            ll notTake = prev[j];
            ll take = (j-a[i] >= 0) ? prev[j - a[i]]: 0;
            curr[j] = notTake | take;
            if(curr[j] == 1)    st.insert(j);
        }
        prev = curr;
    }
    cout << st.size() << endl; 
    for(auto it : st){
        cout << it << " ";
    }
    return 0;
}