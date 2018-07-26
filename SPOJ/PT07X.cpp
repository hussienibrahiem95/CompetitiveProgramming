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
const int N = 1e5 + 20;
vector<vector<int>>gr;
vector<int>vis;
int cnt;
bool dfs_cover_vertex(int node, int p){
	vis[node] = 1;
	bool is_black = 0;
	for (auto nxt : gr[node]){
		if (node == p){
			continue;
		}
		if (!vis[nxt]){
			is_black |= dfs_cover_vertex(nxt, node);
		}
	}
	if (is_black){
		cnt++;
	}
	return !is_black;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	cin >> n;
	gr.resize(n + 1);
	vis.resize(n + 1);
	for (int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	dfs_cover_vertex(1, -1);
	cout << cnt << endl;
}