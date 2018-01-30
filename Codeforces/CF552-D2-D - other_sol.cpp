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
double get_slope(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first){
		return 1e9;
	}

	return (double)(a.second - b.second) / (a.first - b.first);
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	ll n;
	cin >> n;
	vector<pair<double, double>>points;
	for (int i = 0; i < n; i++){
		double x, y;
		cin >> x >> y;
		points.push_back({ x, y });
	}
	ll ans = n* (n - 1) * (n - 2) / 6;
	map<double, int>slopes;
	for (int i = 0; i < n; i++){
		slopes.clear();
		for (int j = i + 1; j < n; j++){
			slopes[get_slope(points[i], points[j])]++;
		}
		map <double, int> ::iterator it;
		for (it = slopes.begin(); it != slopes.end(); ++it) {
			ans -= it->second * (it->second - 1) / 2;
		}
	}

	cout << ans << endl;
}