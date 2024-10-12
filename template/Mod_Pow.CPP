#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define ar array
typedef vector<vector<int>> vvi;
typedef vector<int> vi;  
typedef pair<int,int> pi;
typedef tuple<int,int,int> ti;
int modPow(int a, int b, int mod){
	int ans = 1;
	while(b){
		if(b & 1){
			ans = ans * a;
			ans %= mod;
		}
		a = a * a;
		a %= mod;
		b /= 2;
	}
	return ans;
}