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
pair<int,int> extendEuclid(int a, int b){
	if(b == 0) return {a,0};
	pair<int,int> tmp = extendEuclid(b, a % b);
	return {tmp.second,tmp.first - (a / b) * tmp.second};
}