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
// DSU 
vector<int>parent, rank_v;
void intialize(int n){
	parent.resize(n + 1);
	rank_v.resize(n + 1);
	for (int i = 0; i <= n; i++){
		parent[i] = i;
		rank_v[i] = 1;
	}
}
int findpar(int x){
	if (x == parent[x]){
		return x;
	}
	return parent[x] = findpar(parent[x]);
}
void link(int x, int y){
	if (rank_v[x] > rank_v[y]){ // to put small into big tree
		swap(x, y);
	}
	parent[x] = y;
	if (rank_v[x] == rank_v[y]) {
		rank_v[y]++;
	}
}
bool union_sets(int x, int y){
	x = findpar(x);
	y = findpar(y);
	if (x != y){
		link(x, y);
	}
	return x != y;
}

// MST Kruskal 
struct edge{
	ll from, to, cost;
	bool operator < (const edge &e)const {
		return cost >e.cost;
	}
};
pair < int, vector<edge> > MST_kruskal(int n, vector<edge>gr){
	intialize(n);
	// from , to , cost 
	vector <edge> edges;
	priority_queue<edge> q;
	for (int i = 0; i < gr.size(); i++){
		q.push(gr[i]);
	}
	int min_cost = 0;
	while (!q.empty()){
		// from to , cost
		edge edg = q.top();
		q.pop();
		if (union_sets(edg.from, edg.to)){ // can make link and add this edge 
			min_cost += edg.cost;
			edges.push_back(edg);
		}
	}
	if (edges.size() != n - 1){
		return{ -1, edges };
	}
	return{ min_cost, edges };
}

////////
const int N = 2000 + 20;
int mat[N][N], costs[N][N], vis_dfs[N],n;
bool vis[N][N];
pair < int, vector<edge>> ret; // return of MST 
vector<vector<pair<int,int>>>graph(N); 
void dfs(int src,int node, int cost){
	if (vis_dfs[node])
		return;
	vis_dfs[node] = 1;
	for (int j = 0; j < graph[node].size(); j++){
		int nxt = graph[node][j].first;
		int cost_nxt = graph[node][j].second;
		if (vis_dfs[nxt])
			continue;
		costs[src][nxt] = cost_nxt + cost;
		dfs(src,nxt, cost_nxt + cost);
	}
}
bool check(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j){
				if (mat[i][j] != 0){
					cout << "NO" << endl;
					exit(0);
				}
			}
			else if (mat[i][j] == 0 || mat[i][j]!=mat[j][i]){
				cout << "NO" << endl;
				exit(0);
			}
		}
	}
}
void gen_MST(){
	vector<edge>edges;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j|| vis[i][j]){
				continue;
			}
			vis[j][i] = 1;
			edge e;
			e.from = i + 1;
			e.to = j + 1;
			e.cost = mat[i][j];
			edges.push_back(e);
		}
	}
	ret = MST_kruskal(n, edges);
}
void gen_graph(){
	for (int i = 0; i < ret.second.size(); i++){
		int from, to, cost;
		from = ret.second[i].from;
		to = ret.second[i].to;
		cost = ret.second[i].cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	check();
	gen_MST();
	gen_graph(); 
	for (int i = 1; i <= n; i++){
		clr(vis_dfs, 0);
		dfs(i,i, 0);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j){
				continue;
			}
			if (costs[i + 1][j+1] != mat[i][j]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}