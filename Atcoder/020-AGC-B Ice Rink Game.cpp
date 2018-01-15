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
const int N = 100000 + 20;
int n;
vector<ll>v(N);
ll can(ll md){
	for (int j = 0; j < n; j++){
		md -= (md % v[j]);
	}
	return md;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	ll l = 0, r = 1e18;
	while (l <= r){
		ll md = (l+r) / 2;
		if (can(md)<2){
			l = md + 1;
		}
		else {
			r = md-1;
		}
	}
	ll mn = l,mx;
	r = 1e18;
	l = 2;
	while (l <= r){
		ll md = (l + r) / 2;
		if (can(md)<3){
			l = md + 1;
		}
		else {
			r = md - 1;
		}
	}
	cout << mn << " " << r << endl;
}