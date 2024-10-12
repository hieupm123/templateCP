#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
const int sz = 1e6;
int N,M;
vector<pii> adj[sz];
vi ans, vis(sz);
void dfs(int a){
	while(adj[a].size()){
		pii b = adj[a].back();
		adj[a].pop_back();
		if(!vis[b.s]){
			vis[b.s] = 1;
			dfs(b.f);
		}
	}
	ans.push_back(a);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	for(int i = 0; i < M; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back({b,i + 1});
		adj[b].push_back({a,i + 1});
	}
	for(int i = 1; i <= N; ++i){
		if(adj[i].size() % 2){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
	}
	dfs(1);
	if(ans.size() < M - 1){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	// reverse(ans.begin(),ans.end()); ans.push_back(1);
	for(auto i : ans){
		cout<<i<<" ";
	}
}