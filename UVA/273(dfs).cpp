#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
typedef complex<double> point;
const double EPS = 1e-9;
const int N = 100 + 20;

int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > +EPS)
		return +1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
	return 0;
}

bool intersect(point p1, point p2, point p3, point p4) {
	// special case handling if a segment is just a point
	bool x = (p1 == p2), y = (p3 == p4);
	if (x && y)  return p1 == p3;
	if (x)   return ccw(p3, p4, p1) == 0;
	if (y)   return ccw(p1, p2, p3) == 0;

	return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}
struct line{
	point a, b;
};
map<pair<int, int>, int>connected;
vector<vector<int>>gr;
int vis[N];
void dfs(int src, int node){
	if (vis[node])
		return;
	vis[node] = 1;
	for (int j = 0; j < gr[node].size(); j++){
		int nxt = gr[node][j];
		connected[{src, nxt}] = 1;
		connected[{nxt, src}] = 1;
		dfs(src,nxt);
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
		int n;
		cin >> n;
		connected.clear();
		gr.clear();
		gr.resize(n+1);
		vector<line>lines(n);
		for (int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			point a(x, y);
			cin >> x >> y;
			point b(x, y);
			lines[i].a = a;
			lines[i].b = b;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j){
					continue;
				}
				if (intersect(lines[i].a, lines[i].b, lines[j].a, lines[j].b)){
					gr[i].push_back(j);
					gr[j].push_back(i);
				}
			}
		}
		for (int i = 0; i < n; i++){
			clr(vis, 0);
			dfs(i, i);
		}
		while (1){
			int a, b;
			cin >> a >> b;
			if (a == 0 && b == 0){
				break;
			}
			a--, b--;
			if (a==b||connected[{a, b}]){
				cout << "CONNECTED" << endl;
			}
			else {
				cout << "NOT CONNECTED" << endl;
			}
		}
		if (t!=0)
			cout << endl;
	}
}