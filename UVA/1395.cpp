#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);// freopen("out.txt", "w", stdout);
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 200 + 20;
vector<int>parent, rank_v;
int n, m;
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
struct edge{
	int from, to, cost;
	bool operator < (const edge &e)const {
		return cost > e.cost;
	}
};
int MST_kruskal(int n,vector<edge>gr,int end){
	intialize(n);
	// from , to , cost 
	priority_queue<edge> q;
	vector <edge> edges;
	for (int i = 0; i < end; i++){
		q.push(gr[i]);
	}
	int min_cost = 0;
	int mn = 1e9, mx = 0;
	while (!q.empty()){
		// from to , cost
		edge edg = q.top();
		q.pop();
		if (union_sets(edg.from, edg.to)){ // can make link and add this edge 
			min_cost += edg.cost;
			mn = min(mn, edg.cost);
			mx = max(mx, edg.cost);
			edges.push_back(edg);
		}
	}
	if (edges.size() != n - 1){
		return -1;
	}
	return mx-mn;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	while (cin >> n >> m){
		if (n == 0 && m == 0){
			break;
		}
		vector<edge>gr(m);
		for (int i = 0; i < m; i++){
			int u, v, cost;
			cin >> u >> v >> cost;
			gr[i].from = u;
			gr[i].to = v;
			gr[i].cost = cost;
		}
		sort(all(gr));
		int ret = MST_kruskal(n, gr,gr.size());
		if (ret == -1){
			cout << -1 << endl;
		}
		else {
			int ans = 1e9;
			for (int i = 0; i < m; i++){
				ret = MST_kruskal(n, gr, i+1);
				if (ret == -1)
					continue;
				ans = min(ans, ret);
			}
			cout << ans << endl;
		}
	}
}
