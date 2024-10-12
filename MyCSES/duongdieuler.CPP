#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 3e5 + 100;
vector<int> adj1[M], adj2[M];
vector<int> ans, vis(M);
void eluer(int a){
	while(!adj1[a].empty()){
		int b = adj1[a].back();
		adj1[a].pop_back();
		eluer(b);
	}
	ans.push_back(a);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 0; i < m; ++i){
		int a,b; cin>>a>>b;
		adj1[a].push_back(b);
		adj2[b].push_back(a);
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(((int)adj1[i].size() + (int)adj2[i].size()) % 2){
			++cnt;
		}
	}
	eluer(1);
	reverse(ans.begin(),ans.end());
	if((int)ans.size() != m + 1 || cnt != 2 || ans[(int)ans.size() - 1] != n){
		cout<<"IMPOSSIBLE";
		// cout<<(int)ans.size()<<" "<<cnt<<" "<<ans[(int)ans.size() - 1]<<" ";
		return 0;
	}
	for(int i = 0; i < (int)ans.size(); ++i){
		cout<<ans[i]<<" ";
	}
}