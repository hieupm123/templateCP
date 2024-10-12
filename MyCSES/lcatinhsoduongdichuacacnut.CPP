#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 3e5;
struct node{
	int in = 0, re = 0, mre = 0;
};
vector<int> adj[M], len(M);
vector<vector<int>> dp(M,vector<int>(30));
vector<node> ans(M);
void dfs(int a, int p){
	dp[a][0] = p;
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(b != p){
			len[b] = len[a] + 1;
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
int lowcase(int a, int b){
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
void dfs1(int a, int p){
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(b != p){
			dfs1(b,a);
			ans[a].in += ans[b].in + ans[b].re;
		}
	}
	ans[a].in += ans[a].mre;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 0; i < n - 1; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,1);
	for(int  i = 1; i <= 25; ++i){
		for(int j = 1; j <= n; ++j){
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}
	for(int i = 0; i < m; ++i){
		int a,b; cin>>a>>b;
		int c = lowcase(a,b);
		if(len[a] > len[b]) swap(a,b);
		if(a == c){
			ans[a].re -= 1;
			ans[b].in += 1;
		}else{
			ans[c].mre -= 1;
			ans[a].in += 1;
			ans[b].in += 1;
			ans[c].re -= 1;
		}
	}
	dfs1(1,1);
	for(int i = 1; i <= n; ++i){
		cout<<ans[i].in<<" ";
	}
	return 0;
}