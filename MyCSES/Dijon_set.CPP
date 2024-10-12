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
vi djs(sz), len(sz);
int find(int a){
	while(djs[a] != a){
		a = djs[a];
	}
	return a;
}
void join(int a, int b){
	a = find(a); b = find(b);
	if(len[a] < len[b]){
		swap(a,b);
	}
	len[a] = len[a] + len[b];
	djs[b] = a;
}
int N,M;
vector<tiii> adj;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	for(int i = 0; i < M; ++i){
		int a,b,c; cin>>a>>b>>c;
		adj.push_back(make_tuple(c,a,b));
	}
	for(int i = 1; i <= N; ++i){
		djs[i] = i;
		len[i] = 1;
	}
	sort(adj.begin(),adj.end());
	int ans = 0;
	for(int i = 0; i < (int)adj.size(); ++i){
		int a,b,c; tie(c,a,b) = adj[i];
		if(find(b) != find(a)){
			join(b,a);
			ans += c;
		}
	}
	for(int i = 1; i <= N; ++i){
		if(find(i) != find(1)){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
	}
	cout<<ans<<"\n";
}