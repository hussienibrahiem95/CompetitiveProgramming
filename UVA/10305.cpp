#define _CRT_SECURE_NO_WARNINGS
#includebitsstdc++.h
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen(in.txt, r, stdin); freopen(out.txt, w, stdout);  
#endif
}
void fast(){
	stdios_basesync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
vectorvectorintgr(N);
vectorinttopo_sort;
int vis[N];
int in_degree[N];
void dfs(int node){
	vis[node] = 1;
	for (int i = 0; i  gr[node].size(); i++){
		int nxt = gr[node][i];
		if (!vis[nxt]){
			dfs(nxt);
		}
	}
	topo_sort.push_back(node);
}
void topological_sort_dfs(int n){  n is number of nodes
	for (int i = 1; i = n; i++){
		if (!vis[i])
			dfs(i);
	}
	reverse(all(topo_sort));
}

YouCanDoIt
int main()
{
	file();
	fast();
	int n,m;
	while (cin  m  n){
		if (n == 0 && m == 0){
			break;
		}
		gr.clear();
		gr.resize(m+5);
		topo_sort.clear();
		clr(vis, 0);
		for (int i = 0; i  n; i++){
			int u, v;
			cin  u  v;
			gr[u].push_back(v);
		}
		topological_sort_dfs(m);
		for (int i = 0; i  topo_sort.size()-1; i++){
			cout  topo_sort[i]   ;
		}
		cout  topo_sort[topo_sort.size() - 1]  endl;
	}
}