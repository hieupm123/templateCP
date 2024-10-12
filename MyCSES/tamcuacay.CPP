#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const int M = 2e5 + 100;
int n;
vector<int> adj[M], vis(M),dp(M);
void dfs(int a){
	vis[a] = 1;
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(!vis[b]){
			dfs(b);
			dp[a] += dp[b];
		}
	}
	dp[a]++;
}
int dfs1(int a){
	vis[a] = 1;
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(!vis[b]){
			if(dp[b] * 2 >= n){
				return dfs1(b);
			}
		}
	}
	return a;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i = 0; i < n - 1; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	fill(vis.begin(),vis.end(),0);
	cout<<dfs1(1)<<"\n";
}
