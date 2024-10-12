#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int sz = 2e5 + 5;
int N,Q;
vi adj[sz], vis(sz), len(sz);
vector<vi> dp(sz, vi(30));
void dfs(int a){
    vis[a] = 1;
    for(int i = 0; i < (int)adj[a].size(); ++i){
        int b = adj[a][i];
        if(!vis[b]){
            dp[b][0] = a;
            len[b] = len[a] + 1;
            dfs(b);
        }
    }
}  
int query(int node, int d){
    for(int i = 0; i <= 25; ++i){
        if((1 << i) & d){
            node = dp[node][i];
        }
    }
    return node;
}
int process(int node_a, int node_b){
    if(len[node_a] > len[node_b]) swap(node_a,node_b);
    int d = len[node_b] - len[node_a];
    node_b = query(node_b,d);
    if(node_a == node_b){
        return node_a;
    }
    for(int i = 25; i >= 0; --i){
        if(dp[node_a][i] != dp[node_b][i]){
            node_a = dp[node_a][i];
            node_b = dp[node_b][i];
        }
    }
    return dp[node_a][0];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>Q;
    for(int i = 0; i < N - 1; ++i){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp[1][0] = 1; len[1] = 1;
    dfs(1);
    for(int i = 1; i <= 25; ++i){
        for(int j = 1; j <= N; ++j){
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    for(int i = 0; i < Q; ++i){
        int a,b; cin>>a>>b;
        int node = process(a,b);
        cout<<len[a] - len[node] + len[b] - len[node]<<"\n";
    }
}