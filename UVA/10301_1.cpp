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
const double EPS = 1e-9;
const int N = 510 + 20;
bool is_intersect_circles(double x1, double y1, double r1, double x2, double y2, double r2){
	double x = x1 - x2;
	double y = y1 - y2;
	double dist = sqrt(x*x + y*y);
	return dist < (r1 + r2) && (abs(r1 - r2) <= dist);
}
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
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	while (cin >> n&&n != -1){
		vector<pair<pair<double, double>, double>>circles(n);
		intialize(n + 1);
		for (int i = 0; i < n; i++){
			cin >> circles[i].first.first >> circles[i].first.second;
			cin >> circles[i].second; //  radius
		}
		int mx = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				double r1 = circles[i].second;
				double r2 = circles[j].second;
				if (is_intersect_circles(circles[i].first.first, circles[i].first.second, r1,
					circles[j].first.first, circles[j].first.second, r2)){
					union_sets(i, j);
				}
			}
		}
		map<int, int>mp;
		for (int i = 0; i < n; i++){
			mp[findpar(i)]++;
			mx = max(mx, mp[findpar(i)]);
		}
		if (mx == 1)
			cout << "The largest component contains " << mx << " ring.\n";
		else {
			cout << "The largest component contains " << mx << " rings.\n";
		}
	}
}