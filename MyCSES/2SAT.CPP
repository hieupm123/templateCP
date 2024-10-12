#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 3e5 + 100;
vector<int> adj1[M], adj2[M], vis(M), topo, ans(M); 
int cnt = 0;
void dfs(int a){
	vis[a] = 1;
	for(int i = 0; i < (int)adj1[a].size(); ++i){
		int b = adj1[a][i];
		if(!vis[b]) dfs(b);
	}
	topo.push_back(a);
}
void dfs1(int a){
	vis[a] = 1;
	ans[a] = cnt;
	for(int i = 0; i < (int)adj2[a].size(); ++i){
		int b = adj2[a][i];
		if(!vis[b]){
			dfs1(b);
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		char x,y;
		int a,b; cin>>x>>a>>y>>b;
		if(x == '-') a = 2 * m - a + 1;
		if(y == '-') b = 2 * m - b + 1;
		adj1[a].push_back(2 * m - b + 1);
		adj1[b].push_back(2 * m - a + 1);
		adj2[2 * m - b + 1].push_back(a);
		adj2[2 * m - a + 1].push_back(b);
	}
	for(int i = 1; i <= 2 * m; ++i){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(),topo.end());
	fill(vis.begin(),vis.end(),0);
	for(int i = 0; i < (int)topo.size(); ++i){
		int a = topo[i];
		if(!vis[a]){
			++cnt;
			dfs1(a);
		}
	}
	vector<int> end(M);
	for(int i = 1; i <= m; ++i){
		if(!ans[i]){
			end[i] = 0;
		}
		if(ans[i] == ans[2 * m - i + 1]){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
		if(ans[i] > ans[2 * m - i + 1]){
			end[i] = 0;
		}else{
			end[i] = 1;
		}
	}
	for(int i = 1; i <= m; ++i){
		if(end[i]){
			cout<<"+ ";
		}else{
			cout<<"- ";
		}	
	}
	cout<<"\n";
	return 0;
}