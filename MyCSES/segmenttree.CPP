#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6, inf = 1e18;
vector<int> adj(M), tree(M);
int ans = inf;
void build(int l, int r, int cnt){
	if(l == r){
		tree[cnt] = adj[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,2 * cnt);
	build(mid + 1,r,2 * cnt + 1);
	tree[cnt] = max(tree[2 * cnt],tree[2 * cnt + 1]);
}
void up(int l, int r, int cnt, int a, int b){
	if(a > r || a < l) return;
	if(l == r){
		tree[cnt] = b;
		return;
	}
	int mid = (l + r) / 2;
	up(l,mid,2 * cnt,a,b);
	up(mid + 1,r,2 * cnt + 1,a,b);
	tree[cnt] = max(tree[2 * cnt],tree[2 * cnt + 1]);
}
int query(int l, int r, int cnt, int a){
	if(l == r && tree[cnt] >= a){
		return l;
	}else{
		int mid = (l + r) / 2;
		if(tree[2 * cnt] >= a){
			return min(query(l,mid,2 *cnt,a),ans);
		}
		if(tree[2 * cnt + 1] >= a){
			return min(query(mid + 1,r,2 * cnt + 1,a),ans);
		}
	}
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		cin>>adj[i];
	}
	build(1,n,1);
	for(int i = 0; i < m; ++i){
		int a; cin>>a;
		ans = inf;
		int b = query(1,n,1,a);
		if(b == 1e18){
			cout<<0;
		}else{
			adj[b] -= a;
			up(1,n,1,b,adj[b]);
			cout<<b;
		}
		i == m - 1 ? cout<<"" : cout<<" ";
	}
 
}