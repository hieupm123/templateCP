#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e5 + 100, inf  = 1e18;
const int mod = 1e9 + 7;
vector<pair<int,int>> graph[M];
vector<int> vis(M);
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 0; i < m; ++i){
		int a,b,c; cin>>a>>b>>c;
		graph[a].push_back({b,c});
	}
	priority_queue<pair<int,int>> pq;
	pq.push({0,1});
	vector<int> short_(M,inf), short_max(M), short_min(M), cnt(M);
	short_[1] = 0;
	cnt[1] = 1;
	short_max[1] = 0;
	short_min[1] = 0;
	while(!pq.empty()){
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(vis[node]){
			continue;
		}
		vis[node] = 1;
		for(int i = 0; i < (int)graph[node].size(); ++i){
			auto b = graph[node][i];
			if(-cost + b.second < short_[b.first] && !vis[b.first]){
				short_[b.first] = -cost + b.second;
				cnt[b.first] = cnt[node];
				short_min[b.first] = short_min[node] + 1;
				short_max[b.first] = short_max[node] + 1;
			}else if(-cost + b.second == short_[b.first]){
				cnt[b.first] += cnt[node];
				cnt[b.first] %= mod;
				short_min[b.first] = min(short_min[node] + 1,short_min[b.first]);
				short_max[b.first] = max(short_max[node] + 1,short_max[b.first]);
			}
			pq.push({-(-cost + b.second),b.first});
		}
	}
	cout<<short_[n]<<" "<<cnt[n]<<" "<<short_min[n]<<" "<<short_max[n]<<"\n";
	return 0;
}