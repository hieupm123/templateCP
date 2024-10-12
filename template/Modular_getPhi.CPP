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
int getPhi(int n){
	int ans = 1;
	for(int i = 2; i * i <= n; ++i){
		if(n % i == 0){
			int tmp = i - 1; n /= i;
			while(n % i == 0){
				tmp *= i;
				n /= i;
			}
			ans *= tmp;
		}
	}
	ans *= (n - 1);
	return ans;
}