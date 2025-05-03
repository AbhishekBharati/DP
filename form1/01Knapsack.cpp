#include<bits/stdc++.h>
using namespace std;

int N,W;
int w[3003];
int v[3003];
int dp[3003][3003];

int rec(int level, int x){
    // pruning
    
    // base case
    if(level == N){
        return 0;
    }
    
    // cache check
    if(dp[level][x] != -1){
        return dp[level][x];
    }
    
    // transitions
    int ans = rec(level + 1, x);
    
    if(x >= w[level]){
        ans = max(ans, rec(level + 1, x - w[level]) + v[level]);
    }
    // save and return
    return dp[level][x] = ans;
}

void solve(){
    cin >> N >> W;
    for(int i = 0; i < N; i++){
        cin >> w[i];
    }
    
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0,W) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
}


