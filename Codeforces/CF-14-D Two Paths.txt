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
const int N = 200 + 20;
vector<set<int>>gr(N);
int vis[N];
int n;
vector<int>v;
void dfs(int node){
	if (vis[node] || gr[node].size() == 0)
		return;
	vis[node] = 1;
	v.push_back(node);
	for (auto it : gr[node]){
		int nxt = it;
		dfs(nxt);
	}
}
int dp(int node){
	vis[node] = 1;
	int mx = 0;
	for (auto it : gr[node]){
		int nxt = it;
		if (!vis[nxt]){
			mx = max(mx, 1 + dp(nxt));
		}
	}
	return mx;
}
int solve(){
	vector<int>v1, v2;
	clr(vis, 0);
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			v.clear();
			dfs(i);
			v1 = v;
			break;
		}
	}
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			v.clear();
			dfs(i);
			v2 = v;
			break;
		}
	}
	int mx1 = 0;
	int mx2 = 0;
	for (int i = 0; i < (int)v1.size(); i++){
		clr(vis, 0);
		mx1 = max(mx1, dp(v1[i]));
	}

	for (int i = 0; i < (int)v2.size(); i++){
		clr(vis, 0);
		mx2 = max(mx2, dp(v2[i]));
	}
	return mx1*mx2;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n;
	vector<pair<int, int>>nodes(n);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		nodes[i].first = u;
		nodes[i].second = v;
		gr[u].insert(v);
		gr[v].insert(u);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++){
		int u, v;
		u = nodes[i].first;
		v = nodes[i].second;
		// del
		gr[u].erase(v);
		gr[v].erase(u);
		//get mx
		/*for (int j = 1; j <= n; j++){
		cout << j << " : ";
		for (auto it : gr[j]){
		cout << it << " ";
		}
		cout << endl;
		}*/
		ans = max(ans, solve());
		//add
		gr[u].insert(v);
		gr[v].insert(u);
	}

	cout << ans << endl;
}