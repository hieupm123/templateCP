#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6;
vector<int> A(M), tree(M);
int n,q; 
void up(int a, int b){
	for(int i = a; i <= n; i += (i & (-i))){
		tree[i] += b;
	}
}
int query(int a){
	int ans = 0;
	for(int i = a; i > 0; i -= (i & (-i))){
		ans += tree[i];
	}
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; ++i){
		cin>>A[i];
	}
	for(int i = 0; i < q; ++i){
		int a; cin>>a;
		if(a == 1){
			int b,c,d; cin>>b>>c>>d;
			up(b,d);
			up(c + 1,-d);
		}else{
			int k; cin>>k;
			cout<<A[k] + query(k);
			i == q - 1 ? cout<<"" : cout<<"\n";
		}
	}
}