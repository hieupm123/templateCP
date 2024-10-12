#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 3e5;
vector<int> adj[M], len(M);
vector<vector<int>> dp(M,vector<int>(30));
void dfs(int a, int p){
	dp[a][0] = p;
	for(int j = 0; j < (int)adj[a].size(); ++j){
		int b = adj[a][j];
		if(b != p && !len[b]){
			len[b] = len[a] + 1;
			dp[b][0] = a;
			dfs(b,a);
		}
	}
}
int query(int a, int b){
	for(int i = 0; i <= 25; ++i){
		if(b & (1 << i)){
			a = dp[a][i];
		}
	}
	return a;
}
int process(int a, int b){
	if(len[a] > len[b]){
		swap(a,b);
	}
	b = query(b,len[b] - len[a]);
	if(a == b) return a;
	for(int i = 25; i >= 0; --i){
		if(dp[a][i] != dp[b][i]){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q; cin>>n>>q;
	for(int i = 0; i < n - 1; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	len[1] = 1;
	dfs(1,1);
	for(int i = 1; i <= 25; ++i){
		for(int j = 1; j <= n; ++j){
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}
	for(int i = 0; i < q; ++i){
		int a,b; cin>>a>>b;
		int node = process(a,b);
		int res = len[a] - len[node] + len[b] - len[node];
		cout<<res<<"\n";
	}
	return 0;
}