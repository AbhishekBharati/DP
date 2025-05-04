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
    
    // transitions 1 :-
    int ans = rec(level + 1, x);
    
    if(x >= w[level]){
        ans = max(ans, rec(level, x - w[level]) + v[level]);
    }
    
    // transitions 2 :-
    // int ans = 0;
    // for(int num_of_times = 0; num_of_times <= x/w[level]; num_of_times++){
    //     ans=max(ans, rec(level + 1, x - num_of_times*w[level]) + num_of_times*v[level]);
    // }
    // save and return
    return dp[level][x] = ans;
}

vector<int> solutions;

void generate(int level, int x){
    if(level == N){
        return;
    } else {
        int dontTake = rec(level + 1, x);
        if(w[level] <= x){
            int take = rec(level + 1, x - w[level]) + v[level];
            if(dontTake > take){
                generate(level + 1, x);
            } else {
                solutions.push_back(level);
                generate(level, x - w[level]);
            }
        } else {
            generate(level + 1, x);
        }
    }
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
    generate(0, W);
    for(auto it : solutions){
        cout << it << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
}
