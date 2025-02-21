#include <bits/stdc++.h>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
 
ll findMaxDigit(ll n){
    ll maxi = LLONG_MIN;
    while(n > 0){
        ll lastDigit = n%10;
        maxi = max(maxi, lastDigit);
        n = n/10;
    }
    return maxi;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    //subtract max dight
    ll steps = 0;
    while(n > 0){
        ll maxDigit = findMaxDigit(n);
        n -= maxDigit;
        steps++;
    }
    cout << steps;
    return 0;
}
