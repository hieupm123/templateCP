#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6;
struct node{
	int s = 0, cnt = 1;
};
int n; 
vector<int> adj[M], ans(M);
vector<node> dp(M);
void dfs(int a, int p){
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(b != p){
			dfs(b,a);
			dp[a].s += dp[b].cnt + dp[b].s; 
			dp[a].cnt += dp[b].cnt;
		}
	}
}
void dfs1(int a, int p){
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(b != p){
			dp[b].s = dp[a].s - dp[b].cnt * 2 + n;
			dfs1(b,a);
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n - 1; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,-1);
	dfs1(1,-1);
	for(int i = 1; i <= n; ++i){
		cout<<dp[i].s;
		i == n ? cout<<"" : cout<<" ";
	}
 
}