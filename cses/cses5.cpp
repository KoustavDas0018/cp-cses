#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ll n;
    cin >> n;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
    }
    else{
        for(ll i = 2; i<=n; i+=2){
            cout << i << " ";
        }
        for(ll i = 1; i<=n; i+=2){
            cout << i << " ";
        }
    }
    return 0;
}