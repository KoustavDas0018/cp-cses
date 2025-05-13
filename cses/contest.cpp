#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ord_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define int long long int

using namespace std;
const int MOD= 1e9+7;
const int mod=998244353;
#define MP make_pair
const int N = 50000;

void rotate(vector<string> &s,int n){
	vector<string> x;
	for(int i=0; i<n; i++){
		string temp="";
		for(int j=n-1; j>=0; j--){
			temp += s[j][i];
		}
		x.push_back(temp);
	}
	s = x;
	return;
}

void solve(){
	int n; cin >> n;
	vector<string> s(n),t(n);
	for(int i=0; i<n; i++) cin >> s[i];
	for(int i=0; i<n; i++) cin >> t[i];

	vector<vector<string>> s0(4,vector<string>(n));

	int ans=INT_MAX;
	for(int i=0; i<4; i++){
		int sum=0;
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(s[j][k] != t[j][k]) sum += 1;
			}
		}
		sum += i;
		ans = min(ans,sum);
		rotate(s,n);
	}
	cout << ans << endl;
	
}	
 
signed main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}