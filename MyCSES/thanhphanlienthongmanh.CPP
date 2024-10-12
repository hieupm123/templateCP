#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
const int sz = 1e5 + 5;
int N,M, cnt = 0;
vi topo, vis(sz), adj[sz], radj[sz], ans(sz);
void dfs1(int a){
	vis[a] = 1;
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(!vis[b]){
			dfs1(b);
		}
	}
	topo.push_back(a);
}
void dfs2(int a){
	vis[a] = 1;
	ans[a] = cnt;
	for(int i = 0; i < (int)radj[a].size(); ++i){
		int b = radj[a][i];
		if(!vis[b]){
			dfs2(b);
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	for(int i = 0; i < M; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	for(int i = 1; i <= N; ++i){
		if(!vis[i]){
			dfs1(i);
		}
	}
	reverse(topo.begin(),topo.end());
	fill(vis.begin(),vis.end(),0);
	for(int i : topo){
		if(!vis[i]){
			++cnt;
			dfs2(i);
		}
	}
	cout<<cnt<<"\n";
	for(int i = 1; i <= N; ++i){
		cout<<ans[i]<<" ";
	}
}