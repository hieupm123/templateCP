#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1001;
int n, q;
vector<vector<int>> adj(M,vector<int>(M)), tree(M,vector<int>(M));
void up(int x, int y, int a){
	for(int i = x; i <= n; i += (i & (-i))){
		for(int j = y; j <= n; j += (j & (-j))){
			tree[i][j] += a;
		}
	}
}
int query(int x, int y){
	int ans = 0;
	for(int i = x; i > 0; i -= (i & (-i))){
		for(int j = y; j > 0; j -= (j & (-j))){
			ans += tree[i][j];
		}
	}
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			char cr; cin>>cr;
			if(cr == '*'){
				adj[i][j] = 1;
				up(i,j,1);
			}else{
				adj[i][j] = 0;
				up(i,j,0);
			}
		}
	}
	for(int i = 0; i < q; ++i){
		int check; cin>>check;
		if(check == 1){
			int a, b; cin>>a>>b;
			if(adj[a][b]){
				up(a,b,-1);
				adj[a][b] = 0;
			}else{
				up(a,b,1);
				adj[a][b] = 1;
			}
		}else{
			int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
			cout<<query(x2,y2) - query(x2,y1 - 1) - query(x1 - 1,y2) + query(x1 - 1,y1 - 1);
			i == q - 1 ? cout<<"" : cout<<"\n";
 
		}
	}
 
}