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
const int N = 1e7 + 20;
ll v[N][4], n;
bool can(ll md){
	ll cnt = 0;
	for (int i = 0; i < n; i++){
		ll x = v[i][0];
		ll y = v[i][1];
		ll z = v[i][2];
		ll val = min(md, y);
		if (md<x){
			continue;
		}
		cnt += (val - x) / z + 1;
	}
	return cnt % 2 == 1;
}
ll count_ref(ll md){
	ll cnt = 0;
	for (int i = 0; i < n; i++){
		ll x = v[i][0];
		ll y = v[i][1];
		ll z = v[i][2];
		if (md >= x&&md <= y && (md - x) % z == 0)
			cnt++;
	}
	return cnt;
}

bool check_line(string x){
	for (int i = 0; i < x.size(); i++){
		if (isdigit(x[i])){
			return 1;
		}
	}
	return 0;
}
void solve(){
	ll s = 1, e = (1ll<<32);
	bool ok = 0;
	while (s <= e){
		ll md = (s + e) / 2ll;
		if (can(md)){
			ok = 1;
			e = md - 1;
		}
		else {
			s = md + 1;
		}
	}
	if (!ok){
		cout << "no corruption" << endl;
	}
	else {
		cout << e + 1 << " " << count_ref(e+1) << endl;
	}
	n = 0;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	string x;
	while (getline(cin, x)){
		if (check_line(x)){
			stringstream ss;
			ss << x;
			ss >> v[n][0] >> v[n][1] >> v[n][2];
			n++;
		}
		else {
			if (n != 0){
				solve();
			}
		}
	}
	if (n > 0){
		solve();
	}
}