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
const int sz = 1e8 + 8;
bitset<sz> prime;
void sive(){
	prime[0] = 1; prime[1] = 1;
	for(int i = 2; i * i < sz; ++i){
		if(!prime[i]){
			for(int j = i * i; j < sz; j += i){
				prime[j] = 1;
			}
		}
	}
}