#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define endl "\n"
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 1e6 + 20;
int x;
int mx = 0;
vector<vector<int>>gr(N);
int vis[N];
void dfs(int node, int lvl){
	if (lvl > mx){
		mx = lvl;
		x = node;
	}
	vis[node] = 1;
	for (auto nxt : gr[node]){
		if (!vis[nxt]){
			dfs(nxt, lvl + 1);
		}
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++){
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	dfs(1,0);
	clr(vis, 0); mx = 0;
	int y = x;
	dfs(x, 0);
	cout << mx << endl;
}