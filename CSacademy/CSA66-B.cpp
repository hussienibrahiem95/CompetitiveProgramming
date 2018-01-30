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
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	ll n, x;
	cin >> n >> x;
	ll mn = 1e15;
	vector<pair<ll, ll>>v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(all(v));
	vector<ll>cum(n);
	cum[0] = v[0].second;
	for (int i = 1; i < n; i++){
		cum[i] = cum[i - 1] + v[i].second;
	}
	ll sum = 0;
	for (int i = 0; i < n; i++){
		if (v[i].first >= x){
			mn = min(mn, v[i].first - cum[i]);
		}
		else {
			mn = min(mn, x - cum[i]);
		}
	}
	cout << min(mn,x) << endl;
}