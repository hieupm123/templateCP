#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6, inf = 1e18;
struct node{
	int add = 0; int mx = 0;
};
vector<int> adj[M], pa(M);
vector<node> dp(M);
int ans = -inf;
void dfs(int a, int p){
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(p != b){
			dfs(b,a);
			if(dp[b].mx + 1 > dp[a].mx){
				pa[a] = b;
				dp[a].mx = dp[b].mx + 1;
			}
		}
	}
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(b != p){
			if(pa[a] != b){
				dp[a].add = max(dp[b].mx + 1,dp[a].add);
			}
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
	for(int i = 1; i <= n; ++i){
		ans = max(ans,dp[i].mx + dp[i].add);
	}
	cout<<ans;
}