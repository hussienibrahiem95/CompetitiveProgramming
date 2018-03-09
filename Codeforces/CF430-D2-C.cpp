#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 1e5 + 20;

vector<int>v(N), g(N);
int vis[N];
vector<vector<int>>gr(N);
int ans;
void dfs1(int node, int ev, int od,int level){
	int nw;
	if (vis[node])
		return;
	vis[node] = 1;
	if (level % 2 == 0){
		nw = (v[node] + ev) % 2;
	}
	else {
		nw = (v[node] + od) % 2;
	}
	if (level % 2 == 0){
		if (nw != g[node]){
			ev++;
			ans++;
		}
	}
	else {
		if (nw != g[node]){
			od++;
			ans++;
		}
	}
	for (int i = 0; i < gr[node].size(); i++){
		dfs1(gr[node][i],ev,od,level+1);
	}
}
void dfs2(int node, int ev, int od, int level){
	int nw;
	if (vis[node])
		return;
	vis[node] = 1;
	if (level % 2 == 0){
		nw = (v[node] + ev) % 2;
	}
	else {
		nw = (v[node] + od) % 2;
	}
	if (level % 2 == 0){
		if (nw != g[node]){
			ev++;
			cout << node << "\n";
		}
	}
	else {
		if (nw != g[node]){
			od++;
			cout << node << "\n";
		}
	}
	for (int i = 0; i < gr[node].size(); i++){
		dfs2(gr[node][i], ev, od, level + 1);
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();

	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> g[i];
	}
	dfs1(1,0,0,0);
	cout << ans << endl;
	clr(vis, 0);
	dfs2(1, 0, 0, 0);
}