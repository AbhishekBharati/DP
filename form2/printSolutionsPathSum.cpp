#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> matrix;
int dp[10010][10010];
bool check[10010][10010];

int rec(int row, int col){
    // pruning case
    if(row < 0 || col < 0){
        return -1e9;
    }
    
    // base case
    if(row == 0 && col == 0){
        return matrix[row][col];
    }
    
    // cache check
    if(check[row][col] == 1){
        return dp[row][col];
    }
    
    // transitions
    int ans = rec(row - 1, col) + matrix[row][col];
    ans = max(ans, rec(row, col - 1) + matrix[row][col]);
    
    // return and save
    check[row][col] = 1;
    return dp[row][col] = ans;
}

vector<pair<int,int>> solutions;

void generate(int row, int col){
    // pruning case :-
    if(row < 0 || col < 0){
        return;
    }
    
    // base case :-
    if(row == 0 && col == 0){
        return;
    }
    
    int ans = rec(row - 1, col) + matrix[row][col];
    
    if(ans < rec(row, col - 1) + matrix[row][col]){
        solutions.push_back({row, col - 1});
        generate(row, col - 1);
    } else {
        solutions.push_back({row - 1, col});
        generate(row - 1, col);
    }
}

void solve(){
    cin >> n >> m;
    matrix.resize(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    
    cout << rec(n - 1, m - 1) << '\n';
    solutions.push_back({n - 1, m - 1});
    generate(n - 1, m - 1);
    reverse(solutions.begin(), solutions.end());
    for(auto it : solutions){
        cout << '(' << it.first << ',' << it.second << ')' << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
}
