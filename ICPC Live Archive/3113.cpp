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
	int from, to;
	double cost;
	bool operator < (const edge &e)const {
		return cost >e.cost;
	}
};
pair < double, vector<edge> > MST_kruskal(vector<edge>gr){
	intialize(n);
	// from , to , cost 
	vector <edge> edges;
	priority_queue<edge> q;
	for (int i = 0; i < gr.size(); i++){
		q.push(gr[i]);
	}
	double min_cost = 0;
	while (!q.empty()){
		// from to , cost
		edge edg = q.top();
		q.pop();
		if (union_sets(edg.from,edg.to)){ // can make link and add this edge 
			min_cost += edg.cost;
			edges.push_back(edg);
		}
	}
	if (edges.size() != n - 1){
		return{ -1, edges };
	}
	return{ min_cost, edges };
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	double len;
	
	while (cin >> len){
		cin >> n;
		map<string, int>mp;
		for (int i = 0; i < n; i++){
			string x;
			cin >> x;
			mp[x] = i + 1;
		}
		vector<edge>gr;
		int m;
		cin >> m;
		for (int i = 0; i < m; i++){
			string x, y;
			double cost;
			cin >> x >> y >> cost;
			edge e;
			e.from = mp[x];
			e.to = mp[y];
			e.cost = cost;
			gr.push_back(e);
		}
		pair < double, vector<edge>> ret = MST_kruskal(gr);

		if (ret.first == -1 || ret.first > len){
			cout << "Not enough cable" << endl;
		}
		else {
			cout << fixed << setprecision(1);
			cout << "Need " << ret.first << " miles of cable" << endl;
		}
	}
}
