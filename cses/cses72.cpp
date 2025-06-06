#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define M (ll)(1e9 + 7)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 8;
string chessboard[N];
bool rightDiagonal[2 * (N - 1)], leftDiagonal[2 * (N - 1)], column[N]; // default value is false
int numberOfWays = 0;

void putNext(int r){
    if (r == N){
        numberOfWays++;
        return;
    }
    for (int c = 0; c < N; c++){
        if (column[c] == 0 && leftDiagonal[r - c + N - 1] == 0 && rightDiagonal[r + c] == 0 && chessboard[r][c] == '.'){
            column[c] = leftDiagonal[r - c + N - 1] = rightDiagonal[r + c] = true;
            putNext(r + 1);
            column[c] = leftDiagonal[r - c + N - 1] = rightDiagonal[r + c] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < N; i++){
        cin >> chessboard[i];
    }
    putNext(0);
    cout << numberOfWays;
}