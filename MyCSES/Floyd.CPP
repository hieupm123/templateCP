#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
const int inf = 1e18;
vvi adj(505,vi(505,inf));
int N,M,Q;
void floyd_warshall(){
	for(int i = 1; i <= N; ++i){
		adj[i][i] = 0;
	}
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			for(int k = 1; k <= N; ++k){
				adj[j][k] = min(adj[j][k],adj[j][i] + adj[i][k]);
			}
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M>>Q;
	for(int i = 0; i < M; ++i){
		int a,b,c; cin>>a>>b>>c;
		adj[a][b] = adj[b][a] = min(adj[a][b],c);
	}
	floyd_warshall();
	for(int i = 0; i < Q; ++i){
		int a,b; cin>>a>>b;
		adj[a][b] == inf ? cout<<-1<<"\n" : cout<<adj[a][b]<<"\n";
	}
}