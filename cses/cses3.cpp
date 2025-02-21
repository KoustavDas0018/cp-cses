#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length();
    int len = 1;
    int ans = 1;
    for(int i = 0; i<n-1; i++){
        if(s[i] == s[i+1])  len++;
        ans = max(ans, len);
        if(s[i] != s[i+1]) len = 1;
    }
    cout << ans;
    return 0;
}