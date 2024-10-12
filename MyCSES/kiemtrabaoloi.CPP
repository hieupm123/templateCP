#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
struct P{
	int x,y;
	void read(){
		cin>>x>>y;
	}
	void output(){
		cout<<x<<" "<<y;
	}
}; vector<P> adj;
bool cmp(P p1, P p2){
	return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
}
int cw(P p1, P p2, P p3){
	return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) <= 0;
}
int ccw(P p1, P p2, P p3){
	return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) >= 0;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < n; ++i){
		P a; a.read(); adj.push_back(a);
	}
	sort(adj.begin(),adj.end(),&cmp);
	vector<P> up, down; up.push_back(adj[0]); down.push_back(adj[0]);
	P p1 = adj[0], p2 = adj[(int)adj.size() - 1];
    for (int i = 1; i < (int)adj.size(); i++) {
        if (i == adj.size() - 1 || cw(p1, adj[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], adj[i]))
                up.pop_back();
            up.push_back(adj[i]);
        }
        if (i == adj.size() - 1 || ccw(p1, adj[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], adj[i]))
                down.pop_back();
            down.push_back(adj[i]);
        }
    }
    adj.clear();
    cout<<up.size() + down.size() - 2<<"\n";
    for (int i = 0; i < (int)up.size(); i++)
    	cout<<up[i].x<<" "<<up[i].y<<"\n";
    for (int i = down.size() - 2; i > 0; i--)
        cout<<down[i].x<<" "<<down[i].y<<"\n";
}