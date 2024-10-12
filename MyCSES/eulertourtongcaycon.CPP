// Bạn được cung cấp một cây có gốc bao gồm n nút. Các nút được đánh số 1,2,…,n và nút 1 là gốc. Mỗi nút có một giá trị.

// Nhiệm vụ của bạn là xử lý các loại truy vấn sau:
// thay đổi giá trị của nút s thành x
// tính tổng các giá trị trong cây con của nút s
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6;
vector<int> A(M), B, adj[M], vis(M), pra(M), sw(M), C(M), tree(M);
void dfs(int a){
	vis[a] = 1;
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(!vis[b]){
			dfs(b);
			if(!pra[a]){
				pra[a] = pra[b];
			}
		}
	}
	if(!pra[a]) pra[a] = a;
	B.push_back(a);
}
void build(int l, int r, int cnt){
	if(l == r){
		tree[cnt] = C[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,2 * cnt);
	build(mid + 1,r,2 * cnt + 1);
	tree[cnt] = tree[2 * cnt] + tree[2 * cnt + 1];
}
void up(int l, int r, int cnt, int a, int b){
	if(a < l || a > r){
		return ;
	}
	if(l == r){
		tree[cnt] = b;
		return;
	}
	int mid = (l + r) / 2;
	up(l,mid,2 * cnt,a,b);
	up(mid + 1,r,2 * cnt + 1,a,b);
	tree[cnt] = tree[2 * cnt] + tree[2 * cnt + 1];
}
int query(int l, int r, int cnt, int a, int b){
	if(a > r || b < l){
		return 0;
	}
	if(a <= l && b >= r){
		return tree[cnt];
	}
	int mid = (l + r) / 2;
	return query(l,mid,2 * cnt,a,b) + query(mid + 1,r,2 * cnt + 1,a,b);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q; cin>>n>>q;
	for(int i = 1; i <= n; ++i){
		cin>>A[i];
	}
	for(int i = 0; i < n - 1; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	reverse(B.begin(),B.end());
	for(int i = 0; i < (int)B.size(); ++i){
		sw[B[i]] = i + 1;
		C[i + 1] = A[B[i]];
		// cout<<B[i]<<" "<<i + 1<<"\n";
		// cout<<C[i + 1]<<" ";
	}
	build(1,n,1);
	// cout<<query(1,n,1,2,4);
	for(int i = 0; i < q; ++i){
		int c; cin>>c;
		if(c == 1){
			int a,b; cin>>a>>b;
			up(1,n,1,sw[a],b);
		}else{
			int a; cin>>a;
			// cout<<sw[a]<<" "<<sw[pra[a]]<<"\n";
			cout<<query(1,n,1,sw[a],sw[pra[a]])<<"\n";
		}
	}
	return 0;
}