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
const int N = 510 + 20;
map<int, int> idx1;
map<int, pair<int, int>>circle;
map<int, int>hit;
vector<int>p;
bool is_inside(int x1, int y1, int x2, int y2,int r){
	int dx = (x2 - x1);
	int dy = (y2 - y1);
	return dx*dx + dy*dy <= r * r;
}
void add(int idx,int x2,int y2,int who){
	int r = circle[idx1[p[idx]]].second;
	int x = circle[idx1[p[idx]]].first;
	if (is_inside(x, 0, x2, y2, r)){
		if (hit[idx1[p[idx]]] == 0)
			hit[idx1[p[idx]]] = who;
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n, m;
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++){
		int x, r;
		cin >> x >> r;
		circle[i + 1] = { x, r };
		idx1[x] = i + 1;
		p[i] = x;
	}
	sort(all(p));
	cin >> m;
	for (int i = 0; i < m; i++){
		int x2, y2;
		cin >> x2 >> y2;
		int idx = lower_bound(all(p), x2) - p.begin();
		if (idx < p.size()){
			add(idx, x2, y2, i + 1);
		}
		 if (idx + 1 < (int)p.size()){
			add(idx + 1, x2, y2, i + 1);
		}
		if (idx - 1 >= 0){
			add(idx - 1, x2, y2, i + 1);
		}
	}
	int cnt = 0;
	for (auto it : hit){
		if (it.second != 0){
			cnt++;
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < n; i++){
		if (hit[i + 1] != 0){
			cout << hit[i + 1] << " ";
		}
		else cout << -1 << " ";
	}
}