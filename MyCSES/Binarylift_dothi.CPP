// Bạn đang chơi một trò chơi bao gồm n hành tinh. Mỗi hành tinh có một dịch chuyển tức thời đến một hành tinh khác (hoặc chính hành tinh đó).

// Bạn bắt đầu trên một hành tinh và sau đó du hành qua các máy dịch chuyển tức thời cho đến khi bạn đến một hành tinh mà bạn đã đến trước đó.

// Nhiệm vụ của bạn là tính toán cho mỗi hành tinh số lần dịch chuyển sẽ có nếu bạn bắt đầu trên hành tinh đó.

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int M = 3e5 + 100;
vector<int> graph[M], vis(M), len(M);
int dp[M][35];
void dfs(int a){
	vis[a] = 1;
	if(!vis[dp[a][0]]) dfs(dp[a][0]);
	len[a] = len[dp[a][0]] + 1;
}
int rs(int a, int b){
	for(int i = 0; i < 30; ++i){
		if(b & (1 << i)){
			a = dp[a][i];
		}
	}
	return a;
}
vector<int> ans(M);
void dfs_s(int a){
	for(int i = 0; i < (int)graph[a].size(); ++i){
		int b = graph[a][i];
		if(!ans[b]){
			// cout<<b<<" "<<a<<"\n";
			ans[b] = ans[a] + 1;
			dfs_s(b);
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin>>n;
	for(int i = 1; i <= n; ++i){
		cin>>dp[i][0];
		graph[dp[i][0]].push_back(i);
	}
	for(int i = 1; i < 30; ++i){
		for(int j = 1; j <= n; ++j){
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			dfs(i);
		}
	}
	vector<int> node;
	for(int i = 1; i <= n; ++i){
		int x = rs(i,len[i]);
		// cout<<x<<" "<<len[x]<<"\n";
		if(rs(x,len[x] - len[i]) == i){
			ans[i] = len[x];
			node.push_back(i);
		}
	}
	for(auto i : node){
		dfs_s(i);
	}
	for(int i = 1 ; i <= n; ++i){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}