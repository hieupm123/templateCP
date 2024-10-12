// Bạn được cung cấp một chuỗi có độ dài n và một từ điển chứa k từ. Có bao nhiêu cách bạn có thể tạo chuỗi bằng cách sử dụng các từ?
// Input:
// ababc
// 4
// ab
// abab
// c
// cb

// Output:
// 2

// Explanation: The possible ways are ab+ab+c and abab+c.
#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const int M = 1e6 + 100, mod = 1e9 + 7;
struct node{
	map<char,int> to;
	bool check;
};
vector<node> trie(M);
int dp[M], ct = 0;
string s;
void insert(string s){
	int node = 0;
	for(int i = 0; i < (int)s.size(); ++i){
		if(!trie[node].to[s[i]]){
			trie[node].to[s[i]] = ++ct;
		}
		node = trie[node].to[s[i]];
	}
	trie[node].check = 1;
}
int query(int a){
	int node = 0, ans = 0;
	for(int i = a; i < (int)s.size(); ++i){
		if(!trie[node].to[s[i]]){
			return ans;
		}
		node = trie[node].to[s[i]];
		if(trie[node].check){
			ans += dp[i + 1];
			ans %= mod;
		}
	}
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
   int k; cin>>s>>k;
   for(int i = 0; i < k; ++i){
   	string t; cin>>t;
   	insert(t);
   }
   dp[(int)s.size()] = 1;
   for(int i = (int)s.size() - 1; i >= 0; --i){
   	dp[i] = query(i);
   }
   cout<<dp[0];
   return 0;
}