#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool inbounds(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void printsolution(int x, int y, int d2[][1000], char p[][1000]) {
    int d = d2[x][y];
    cout << "YES" << endl << d << endl;
    char ans[d];
    for(int i = d - 1; i >= 0; i--){
        ans[i] = p[x][y];
        if(ans[i] == 'D')       x--;
        else if(ans[i] == 'U')  x++;
        else if(ans[i] == 'R')  y--;
        else if(ans[i] == 'L')  y++;
    }
    for(int i = 0; i < d; i++) cout << ans[i];
    cout << endl;
}

void solve(){
    int n, m, sx, sy;
    cin >> n >> m;
    int h[] = {1, -1, 0, 0};
    int v[] = {0, 0, 1, -1};
    bool vis[n][m];
    char c[n][m], p[n][m];
    int d1[n][m], d2[n][m];
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
            if(c[i][j] == '#')  vis[i][j] = true;
            else if(c[i][j] == 'M'){
                vis[i][j] = true;
                q.push({i, j});
            } else if(c[i][j] == 'A'){
                sx = i; sy = j;
            }
        }
    }

    while(!q.empty()){
        auto p = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int x = p.first + h[i], y = p.second + v[i];
            if(inbounds(x, y, n, m) && !vis[x][y]){
                d1[x][y] = d1[p.first][p.second] + 1;
                vis[x][y] = true;
                q.push({x, y});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j])  d1[i][j] = INF;
            vis[i][j] = (c[i][j] == '#');
        }
    }

    vis[sx][sy] = true;
    q.push({sx, sy});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int x = p.first + h[i], y = p.second + v[i];
            if(inbounds(x, y, n, m) && !vis[x][y] && d2[p.first][p.second] + 1 < d1[x][y]){
                if(i == 0)      p[x][y] = 'D';
                else if(i == 1) p[x][y] = 'U';
                else if(i == 2) p[x][y] = 'R';
                else if(i == 3) p[x][y] = 'L';
                d2[x][y] = d2[p.first][p.second] + 1;
                vis[x][y] = true;
                q.push({x, y});
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(c[i][0] != '#' && c[i][0] != 'M' && vis[i][0]){
            printsolution(i, 0, d2, p);
            return;
        }
        else if(c[i][m-1] != '#' && c[i][m-1] != 'M' && vis[i][m-1]){
            printsolution(i, m - 1, d2, p);
            return;
        }
    }

    for(int i = 0; i < m; i++){
        if(c[0][i] != '#' && c[0][i] != 'M' && vis[0][i]){
            printsolution(0, i, d2, p);
            return;
        }
        else if(c[n - 1][i] != '#' && c[n - 1][i] != 'M' && vis[n - 1][i]){
            printsolution(n - 1, i, d2, p);
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
