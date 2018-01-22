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
bool can(ll x){
	ll m = sqrt(x);
	if (m*m == x){
		return 1;
	}
	return 0;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();

	int n;
	cin >> n;
	vector<ll>v(n);
	ll mx = -1e9;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		if (!can(v[i])){

			mx = max(mx, v[i]);
		}
	}
	cout << mx << endl;
}