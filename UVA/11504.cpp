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
int vis[N];
vector<vector<int>>gr, oth,temp;
vector<int>tological_elmn, component;
vector<vector<int>>components;
int n, m, c,ans;
// topological_sort
void dfs1(int node){
	vis[node] = 1;
	for (auto nxt : gr[node]){
		if (!vis[nxt]){
			dfs1(nxt);
		}
	}
	tological_elmn.push_back(node);
}
void dfs2(int node){
	vis[node] = 1;
	component.push_back(node);
	for (auto nxt : gr[node]){
		if (!vis[nxt]){
			dfs2(nxt);
		}
	}
}
void connect_CC(){
	map<int, int>node_cmp;
	int cmp_num = 1;
	int capit_comp = 1;
	for (auto comp : components){
		for (auto node : comp){
			if (node == c){
				capit_comp = cmp_num;
			}
			node_cmp[node] = cmp_num;
		}
		cmp_num++;
	}
	vector<set<int>>gr_comp(N);
	vector<int>inDeg(N);
	for (int i = 1; i <= n; i++){
		for (auto nxt : gr[i]){
			if (node_cmp[i] != node_cmp[nxt]){
				gr_comp[node_cmp[i]].insert(node_cmp[nxt]);
				inDeg[node_cmp[nxt]]++;
			}
		}
	}
	for (int i = 1; i < cmp_num; i++){
		if (!inDeg[i]){
			ans++;
		}
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		gr.clear(); gr.resize(n + 5), oth.clear();
		oth.resize(n + 5);
		temp.clear();
		temp.resize(n + 5);
		tological_elmn.clear();
		components.clear();
		ans = 0;
		clr(vis, 0);
		for (int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			gr[u].push_back(v);
			oth[v].push_back(u);
		}
		for (int i = 1; i <= n; i++){
			if (!vis[i]){
				dfs1(i);
			}
		}
		clr(vis, 0);
		reverse(all(tological_elmn));
		temp = gr;
		gr = oth;
		for (int i = 0; i < tological_elmn.size(); i++){
			if (!vis[tological_elmn[i]]){
				component.clear();
				dfs2(tological_elmn[i]);
				components.push_back(component);
			}
		}
		gr = temp;
		connect_CC();
		cout << ans << endl;
	}
}