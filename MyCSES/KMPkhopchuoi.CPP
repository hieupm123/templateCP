#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
vector<int> cnt;
void KMP(string s){
	int n = (int)s.size();
	cnt.resize(n + 100);
	for(int i = 1; i < n; ++i){
		int j = cnt[i - 1];
		while(j > 0 && s[i] != s[j]){
			j = cnt[j - 1];
		}
		if(s[i] == s[j]){
			++j;
		}
		cnt[i] = j;
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
   string n,m; cin>>n>>m;
   int ans = 0; string S = m + "%" + n;
   KMP(S);
   for(int i = 0; i < (int)cnt.size(); ++i){
   	if(cnt[i] == (int)m.size()){
   		++ans;
   	}
   }
   cout<<ans;
   return 0;
}