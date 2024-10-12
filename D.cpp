#include <bits/stdc++.h>
#define int long long
using namespace std;
int fa[100005],a[100005],tag[100005],l[100005],r[100005];
map <int,int> mp;
inline void dfs(int u,int L,int R)
{
	if(a[u]<=R&&a[u]>=L) mp[a[u]]=1;
	if(l[u]!=-1) dfs(l[u],L,min(R,a[u]));
	if(r[u]!=-1) dfs(r[u],max(L,a[u]),R);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i] >> l[i] >> r[i];
	for(int i=1;i<=n;i++)
	{
		if(l[i]!=-1&&a[l[i]]>a[i]) tag[l[i]]=1;
		if(r[i]!=-1&&a[r[i]]<a[i]) tag[r[i]]=1;
		if(l[i]!=-1) fa[l[i]]=i;
		if(r[i]!=-1) fa[r[i]]=i;
	}
	int rt=0;
	for(int i=1;i<=n;i++)
		if(!fa[i]) rt=i;
	dfs(rt,-1e9,2e9);
	int ans=n;
	for(int i=1;i<=n;i++) ans-=mp[a[i]];
    for(auto [a, b] : mp){
        cout<<a<<" "<<b<<"\n";
    }
	cout << ans;
	return 0;
}