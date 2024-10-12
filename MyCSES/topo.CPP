#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e5 + 100;
vector<int> graph[M], vis(M), topo, pa(M);
void dfs(int a){
	vis[a] = 1;
	for(int i = 0; i < (int)graph[a].size(); ++i){
		int b = graph[a][i];
		if(!vis[b]){
			dfs(b);
		}
	}
	topo.push_back(a);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 0; i < m; ++i){
		int a,b; cin>>a>>b;
		graph[a].push_back(b);
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(), topo.end());
	// for(auto i : topo){
	// 	cout<<i<<" ";
	// }
	vector<int> dp(M);
	dp[1] = 1;
	for(int i = 0; i < (int)topo.size(); ++i){
		int a = topo[i];
		for(int j = 0; j < (int)graph[a].size(); ++j){
			int b = graph[a][j];
			if(dp[a] + 1 > dp[b] && dp[a]){
				pa[b] = a;
				dp[b] = dp[a] + 1;
 
			}
		}
	}
	// for(int i = 1; i <= n; ++i){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<"\n";
	if(dp[n] == 0){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	vector<int> ans;
	ans.push_back(n);
	int id = pa[n];
	while(id != 1){
		ans.push_back(id);
		id = pa[id];
	}
	ans.push_back(1);
	reverse(ans.begin(),ans.end());
	cout<<(int)ans.size()<<"\n";
	for(int i = 0; i < (int)ans.size(); ++i){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
 
	return 0;
}