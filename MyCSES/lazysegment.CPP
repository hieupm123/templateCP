// Nhiệm vụ của bạn là duy trì một mảng n giá trị và xử lý hiệu quả các loại truy vấn sau:
// Tăng từng giá trị trong phạm vi [a,b] lên x.
// Đặt từng giá trị trong phạm vi [a,b] thành x.
// Tính tổng các giá trị trong phạm vi [a,b].

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6;
struct node{
	int in = 0, val = 0, se = 0;
};
vector<int> adj(M);
vector<node> tree(M);
void build(int l, int r, int cnt){
	if(l == r){
		tree[cnt].val = adj[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,2 * cnt);
	build(mid + 1,r,2 * cnt + 1);
	tree[cnt].val = tree[2 * cnt].val + tree[2 * cnt + 1].val;
}
void down(int l, int r, int cnt){
	int a = 2 * cnt, b = 2 * cnt + 1;
	int mid = (l + r) / 2;
	if(tree[cnt].se){
		tree[a].se = tree[b].se = tree[cnt].se;
		tree[a].val = tree[cnt].se * (mid - l + 1);
		tree[b].val = tree[cnt].se * (r - mid); 
		tree[a].in = tree[b].in = 0;
	}else{
		if(tree[a].se){
			tree[a].se += tree[cnt].in;
			tree[a].in = 0;
		}else{
			tree[a].in += tree[cnt].in;
		}
		if(tree[b].se){
			tree[b].se += tree[cnt].in;
			tree[b].in = 0;
		}else{
			tree[b].in += tree[cnt].in;
		}
		tree[a].val += tree[cnt].in  * (mid - l + 1);
		tree[b].val += tree[cnt].in * (r - mid);
		}
	tree[cnt].se = 0;
	tree[cnt].in = 0;
}
void up(int l, int r, int cnt, int a, int b, int c, int d){
	if(b < l || a > r){
		return;
	}
	if(a <= l && b >= r){
		if(c == 1){
			if(tree[cnt].se){
				tree[cnt].se += d;
			}else{
				tree[cnt].in += d;
			}
			tree[cnt].val += d * (r - l + 1);
		}else{
			tree[cnt].val = d * (r - l + 1);
			tree[cnt].se = d;
			tree[cnt].in = 0;
		}
		return;
	}
	down(l,r,cnt);
	int mid = (l + r) / 2;
	up(l,mid,2 * cnt,a,b,c,d);
	up(mid + 1,r,2 * cnt + 1,a,b,c,d);
	tree[cnt].val = tree[2 * cnt].val + tree[2 * cnt + 1].val;
}
int query(int l, int r, int cnt, int a, int b){
	if(a > r || b < l){
		return 0;
	}
	if(a <= l && b >= r){
		return tree[cnt].val;
	}
	down(l,r,cnt);
	int mid = (l + r) / 2;
	return query(l,mid,2 * cnt,a,b) + query(mid + 1,r,2 * cnt + 1,a,b);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q; cin>>n>>q;
	for(int i = 1; i <= n; ++i){
		cin>>adj[i];
	}
	build(1,n,1);
	for(int i = 0; i < q; ++i){
		int c; cin>>c;
		if(c == 1 || c == 2){
			int a,b,d; cin>>a>>b>>d;
			up(1,n,1,a,b,c,d);
		}else{
			int a,b; cin>>a>>b;
			cout<<query(1,n,1,a,b)<<"\n";
		}
	}
}