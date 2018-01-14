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
const int N = 1e3 + 20;
typedef complex<double> point;
#define X real()
#define Y imag()
point points[N];
ll n, s;
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n >> s;
	ll sum = 0;
	vector<int>popul(n);
	for (int i = 0; i < n; i++){
		ll x, y, z;
		cin >> x >> y >> popul[i];
		point a(x, y);
		points[i] = a;
		sum += popul[i];
	}
	vector<pair<double, int>>dist;
	for (int i = 0; i < n; i++){
		dist.push_back({ points[i].X*points[i].X + points[i].Y * points[i].Y, popul[i] });
	}
	sort(all(dist));
	for (int i = 0; i < n; i++){
		s += dist[i].second;
		if (s >= 1e6){
			cout << fixed << setprecision(10);
			cout << sqrt(dist[i].first) << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}