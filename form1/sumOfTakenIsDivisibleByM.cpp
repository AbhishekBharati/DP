#include<bits/stdc++.h>
using namespace std;

int N,W,K,M;
int w[3003];
int v[3003];
int dp[101][1001][101];

int rec(int level, int x, int item_left){
    // pruning
    
    // base case
    if(level == N){
        int sum_taken = (W - x);
        if(sum_taken%M == 0){
            return 0;
        } else {
            return -1e9;
        }
    }
    
    // cache check
    if(dp[level][x][item_left] != -1){
        return dp[level][x][item_left];
    }
    
    // transitions 1 :-
    int ans = rec(level + 1, x, item_left);
    
    if(x >= w[level] && item_left > 0){
        ans = max(ans, rec(level, x - w[level], item_left - 1) + v[level]);
    }
    
    // transitions 2 :-
    // int ans = 0;
    // for(int num_of_times = 0; num_of_times <= x/w[level]; num_of_times++){
    //     ans=max(ans, rec(level + 1, x - num_of_times*w[level]) + num_of_times*v[level]);
    // }
    // save and return
    return dp[level][x][item_left] = ans;
}

vector<int> solutions;

void generate(int level, int x, int item_left){
    if(level == N){
        return;
    } else {
        int dontTake = rec(level + 1, x, item_left);
        if(w[level] <= x && item_left > 0){
            int take = rec(level + 1, x - w[level], item_left - 1) + v[level];
            if(dontTake > take){
                generate(level + 1, x, item_left);
            } else {
                solutions.push_back(level);
                generate(level, x - w[level], item_left - 1);
            }
        } else {
            generate(level + 1, x, item_left);
        }
    }
}

void solve(){
    cin >> N >> W >> K >> M;
    for(int i = 0; i < N; i++){
        cin >> w[i];
    }
    
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0,W, K) << "\n";
    generate(0, W, K);
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
