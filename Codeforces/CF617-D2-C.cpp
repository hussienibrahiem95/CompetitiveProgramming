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
const int N = 2000 + 20;
ll n, k;
int x11, y11, x22, y22;
pair<int, int> a[N];
bool vis[N];
ll dist(int x1, int y1, int x2, int y2){
	double x = x1 - x2;
	double y = y1 - y2;
	return (x*x + y*y);
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n >> x11 >> y11 >> x22 >> y22;
	vector<pair<ll, ll>>diss;
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		double d1 = dist(a[i].first, a[i].second, x11, y11);
		double d2 = dist(a[i].first, a[i].second, x22, y22);
		diss.push_back({ d1, d2 });

	}
	diss.push_back({ 0, 0 });
	ll ans = 1e18;
	for (int i = 0; i < diss.size(); i++){
		ll r1 = diss[i].first;
		ll r2 = 0;
		for (int j = 0; j < diss.size(); j++){
			if (diss[j].first>r1){
				r2 = max(r2, diss[j].second);
			}
		}
		ans = min(ans, r1 + r2);
	}
	cout << ans << endl;
}