#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxx(a,b,c) max(a,max(b,c))
const int M = 1e6, inf = 1e18;
struct node{
	int add = 0, s = 0;
};
vector<int> adj[M], pa(M), ans(M);
vector<node> dp(M);
void dfs(int a, int p){
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(b != p){
			dfs(b,a);
			if(dp[b].s + 1 > dp[a].s){
				dp[a].s = dp[b].s + 1;
				pa[a] = b;
			}
		}
	}
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(b != p){
			if(b != pa[a]){
				dp[a].add = max(dp[a].add,dp[b].s + 1);
			}
		}
	}
}
void dfs1(int a, int p){
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(p != b){
			if(b == pa[a]){
				dp[b].add = max(dp[a].add + 1,dp[b].add);
			}else{
				dp[b].add = maxx(dp[a].s + 1,dp[a].add + 1,dp[b].add);
			}
			dfs1(b,a);
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin>>n;
	for(int i = 1; i <= n - 1; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,-1);
	dfs1(1,-1);
	for(int i = 1; i <= n; ++i){
		cout<<max(dp[i].s,dp[i].add);
		i == n ? cout<<"" : cout<<" ";
	}
}