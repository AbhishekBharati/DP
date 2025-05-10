#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<char>> mat;

int dp[1001][1001];

int rec(int row, int col){
    // pruning case :-
    if(row < 0 || col < 0 || row >= n || col >= m || mat[row][col] == '#' ){
        return 0;
    }
    
    // base case :-
    if(row == 0 && col == 0){
        return 1;
    }
    
    // cache check :-
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    
    // transition :-
    int ans = rec(row - 1, col) + rec(row, col - 1);
    
    return dp[row][col] = ans;
}

void solve(){
    cin >> n >> m;
    mat.resize(n, vector<char>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << rec(n - 1, m - 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
