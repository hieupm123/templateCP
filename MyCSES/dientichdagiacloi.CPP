// Nhiệm vụ của bạn là tính diện tích của một đa giác đã cho.

// Đa giác gồm n đỉnh (x1,y1),(x2,y2),…,(xn,yn). Các đỉnh (xi,yi) và (xi+1,yi+1) kề nhau với i=1,2,…,n−1, và các đỉnh (x1,y1) và (xn,yn) cũng kề nhau.
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>> adj;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < n; ++i){
		int a,b; cin>>a>>b;
		adj.push_back({a,b});
	}
	int ans = adj[0].second * adj[n - 1].first - adj[0].first * adj[n - 1].second;
	for(int i = 0; i < n - 1; ++i){
		ans = ans + adj[i].first * adj[i + 1].second - adj[i + 1].first * adj[i].second;
	}
	cout<<abs(ans);
 
	return 0;
}