#include<bits/stdc++.h>

using namespace std;
#define int long long

int n, x;
int arr[1001];
int dp[1001][101];

int rec(int level, int x){
    // pruning case
    if(x < 0){
        // Invalid
        return 1e9;
    }
    
    // base case
    if(level == -1){
        if(x == 0){
            return 0;
        } else {
            // Invalid
            return 1e9;
        }
    }
    
    // cache check
    if(dp[level][x] != -1){
        return dp[level][x];
    }
    
    // transitions
    int ans = 1e9;
    int min_seen = arr[level];
    for(int j = level - 1; j >= -1; j--){
        ans = min(ans, rec(j, x - 1) + min_seen);
        if(j != -1){
            min_seen = min(min_seen, arr[j]);
        }
    }
    // save and return
    return dp[level][x] = ans;
}

void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(n - 1, x) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
}
