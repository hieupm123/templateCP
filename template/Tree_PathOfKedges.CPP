#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const int M = 2e5 + 100;
vector<int> vis(M), adj[M];
int sub[M], ans = 0, n, k, max_depth = 0, cnt[M]{1};
void dfs(int a, int p){
	sub[a] = 1;
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(!vis[b] && p != b){
			dfs(b,a);
			sub[a] += sub[b];
		}
	}
}
int center(int a, int p, int dr){
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(!vis[b] && p != b){
			if(sub[b] * 2> dr){
				return center(b,a,dr);
			}
		}
	}
	return a;
}
void get_ans(int a, int p, int check, int depth){
	if(depth > k){
		return;
	}
	max_depth = max(depth,max_depth);
	if(check){
		cnt[depth]++;
	}else{
		ans += cnt[k - depth];
	}
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(!vis[b] && p != b){
			get_ans(b,a,check,depth + 1);
		}
	}
}
void process(int a){
	dfs(a,-1);
	int node = center(a,-1,sub[a]);
	vis[node] = 1;
	max_depth = 0;
	for(int i = 0; i < (int)adj[node].size(); ++i){
		int b = adj[node][i];
		if(!vis[b]){
			get_ans(b,node,0,1);
			get_ans(b,node,1,1);
		}
	}
	fill(cnt + 1,cnt + max_depth + 1,0);
	for(int i = 0; i < (int)adj[node].size(); ++i){
		int b = adj[node][i];
		if(!vis[b]){
			process(b);
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
   cin>>n>>k;
   for(int i = 0; i < n - 1; ++i){
   	int a,b; cin>>a>>b;
   	adj[a].push_back(b);
   	adj[b].push_back(a);
   }
   process(1);
   cout<<ans;
   return 0;
}