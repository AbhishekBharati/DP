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

vector<int> solutions;

void generate(int level){
    
    if(level == -1){
        return;
    }
    
    solutions.push_back(arr[level]);
    
    int ans = -1;
    int elem = -1;
    for(int i = 0; i < level; i++){
        if(arr[i] < arr[level]){
            if(rec(i) > ans){
                ans = rec(i);
                elem = i;
            }
        }
    }
    
    generate(elem);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];  
    }
    memset(dp, -1, sizeof(dp));
    int best = -1;
    int elem = -1;
    for(int i = 0; i < n; i++){
        if(rec(i) > best){
            best = rec(i);
            elem = i;
        }
    }
    
    generate(elem);
    cout << best << "\n";
    reverse(solutions.begin(), solutions.end());
    for(auto it : solutions){
        cout << it << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
}
