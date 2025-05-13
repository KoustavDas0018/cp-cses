#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int MOD = 1e9 + 7;
int INF = 1e9;
ll LLINF = 1e18;

void addToLower(int x, multiset<int>& lower_half, multiset<int>& upper_half, ll& sum_lower_half, ll& sum_upper_half, int k){
    if(lower_half.empty() || x <= *lower_half.rbegin()){
        lower_half.insert(x);
        sum_lower_half += x;
    } else {
        upper_half.insert(x);
        sum_upper_half += x;
    }
    if(lower_half.size() > (k + 1) / 2){
        sum_upper_half += *lower_half.rbegin();
        sum_lower_half -= *lower_half.rbegin();
        upper_half.insert(*lower_half.rbegin());
        lower_half.erase(prev(lower_half.end()));
    }
    while(upper_half.size() > k / 2){
        sum_lower_half += *upper_half.begin();
        sum_upper_half -= *upper_half.begin();
        lower_half.insert(*upper_half.begin());
        upper_half.erase(upper_half.begin());
    }
}

void removeFromSets(int x, multiset<int>& lower_half, multiset<int>& upper_half, ll& sum_lower_half, ll& sum_upper_half){
    if(lower_half.find(x) != lower_half.end()){
        lower_half.erase(lower_half.find(x));
        sum_lower_half -= x;
    } else {
        upper_half.erase(upper_half.find(x));
        sum_upper_half -= x;
    }
    if(lower_half.empty()){
        sum_lower_half += *upper_half.begin();
        sum_upper_half -= *upper_half.begin();
        lower_half.insert(*upper_half.begin());
        upper_half.erase(upper_half.begin());
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    multiset<int> lower_half, upper_half;
    ll sum_lower_half = 0, sum_upper_half = 0;
    lower_half.insert(arr[0]);
    sum_lower_half += arr[0];
    for(int i = 1; i < k; i++){
        addToLower(arr[i], lower_half, upper_half, sum_lower_half, sum_upper_half, k);
    }
    cout << sum_upper_half - sum_lower_half + (k % 2) * (*lower_half.rbegin()) << ' ';
    for(int i = k; i < n; i++){
        if(k == 1){
            addToLower(arr[i], lower_half, upper_half, sum_lower_half, sum_upper_half, k);
            removeFromSets(arr[i - k], lower_half, upper_half, sum_lower_half, sum_upper_half);
        }
        else {
            removeFromSets(arr[i - k], lower_half, upper_half, sum_lower_half, sum_upper_half);
            addToLower(arr[i], lower_half, upper_half, sum_lower_half, sum_upper_half, k);
        }
        cout << sum_upper_half - sum_lower_half + (k % 2) * (*lower_half.rbegin()) << ' ';
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    // cin >> t;

    while(tc--){
        solve();
    }

    return 0;
}
