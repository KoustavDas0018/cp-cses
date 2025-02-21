#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n-1);
    for(int i = 0; i<n-1; i++){
        cin >> a[i];
    }
    ll s1 = 0, s2 = 0;
    for(int i = 0; i<n-1; i++){
        s1 += (ll)(a[i]);
    }
    s2 = (ll)n*(n+1)/2;
    cout << (s2-s1) << endl;
    return 0;
}