#include<bits/stdc++.h>

using namespace std;

int n;
int arr[10010];
int dp[10010];

int rec(int level){
    // pruning
    
    // base case
    if(level == -1){
        return -1e9;
    }
    
    // dp check
    if(dp[level] != -1){
        return dp[level];
    }
    
    // transitions
    int ans = 1;
    for(int prevLevel = 0; prevLevel < level; prevLevel++){
        if(arr[level] > arr[prevLevel]){
            ans = max(rec(prevLevel) + 1, ans);
        }
    }
    
    // save and return
    return dp[level] = ans;
}


void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];  
    }
    memset(dp, -1, sizeof(dp));
    int best = -1;
    for(int i = 0; i < n; i++){
        best = max(rec(i), best);
    }
    

    cout << best << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
}
