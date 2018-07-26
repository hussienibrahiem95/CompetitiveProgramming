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
vector<vector<int>>gr(N);
int dfs_num[N], dfs_low[N], dfs_number, dfs_root, cnt_child;
vector<vector<int>>components;
vector<int>component,stk,in_stack(N),vis(N);
int n, m;
void Trijan_CC(int node){
	dfs_num[node] = dfs_low[node] = ++dfs_number;
	in_stack[node] = 1;
	stk.push_back(node);
	for (auto nxt : gr[node]){
		if (!dfs_num[nxt]){
			Trijan_CC(nxt);
			dfs_low[node] = min(dfs_low[node], dfs_low[nxt]);
		}
		if (in_stack[nxt]){ // back edge 
			dfs_low[node] = min(dfs_low[node], dfs_num[nxt]);
		}
	}
	if (dfs_low[node] == dfs_num[node]){
		while (1){
			int nxt = stk.back(); stk.pop_back(); in_stack[nxt] = 0;
			component.push_back(nxt);
			if (nxt == node){
				break;
			}
		}
		components.push_back(component);
		component.clear();
	}
}
vector<int>ans;
void connect_CC(){
	map<int, int>node_cmp;
	int cmp_num = 1;
	for (auto comp : components){
		for (auto node : comp){
			node_cmp[node] = cmp_num;
		}
		cmp_num++;
	}
	vector<set<int>>gr_comp(N);
	vector<int>outDeg(N);
	for (int i = 1; i <= n; i++){
		for (auto nxt : gr[i]){
			if (node_cmp[i] != node_cmp[nxt]){
				gr_comp[node_cmp[i]].insert(node_cmp[nxt]);
				outDeg[node_cmp[i]]++;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i < cmp_num; i++){
		if (outDeg[i] == 0){
			cnt++;
		}
	}
	if (cnt>1){
		return;
	}
	cmp_num = 1;
	for (auto comp : components){
		if (outDeg[cmp_num] == 0){
			for (auto node : comp){
				ans.push_back(node);
			}
			return;
		}
		cmp_num++;
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
	}
	for (int i = 1; i <= n; i++){
		if (!dfs_num[i]){
			Trijan_CC(i);
		}
	}
	connect_CC();
	cout << ans.size() << endl;
	sort(all(ans));
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
}